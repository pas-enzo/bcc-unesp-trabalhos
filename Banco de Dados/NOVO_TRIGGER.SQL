USE trabalho_bd;

-- Drop existing triggers to avoid conflicts
DROP TRIGGER IF EXISTS before_insert_pagamentos;
DROP TRIGGER IF EXISTS after_insert_pagamentos;
DROP TRIGGER IF EXISTS before_update_pagamentos;
DROP TRIGGER IF EXISTS after_update_pagamentos;
DROP TRIGGER IF EXISTS verificar_assinatura;

DELIMITER //

-- Trigger BEFORE INSERT on Pagamentos
CREATE TRIGGER before_insert_pagamentos
BEFORE INSERT ON Pagamentos
FOR EACH ROW
BEGIN
    DECLARE id_assinatura INT;
    
    -- Verifica se há uma assinatura associada ao pagamento
    SELECT idAssina INTO id_assinatura FROM Assinaturas WHERE idPlano = NEW.idPlano;
    
    -- Se houver uma assinatura, remove-a das tabelas de estado
    IF id_assinatura IS NOT NULL THEN
        DELETE FROM Assinatura_Ativa WHERE idAssina = id_assinatura;
        DELETE FROM Assinatura_Atrasada WHERE idAssina = id_assinatura;
    END IF;
END;
//

-- Trigger AFTER INSERT on Pagamentos
CREATE TRIGGER after_insert_pagamentos
AFTER INSERT ON Pagamentos
FOR EACH ROW
BEGIN
    DECLARE id_assinatura INT;
    
    -- Verifica se há uma assinatura associada ao pagamento
    SELECT idAssina INTO id_assinatura FROM Assinaturas WHERE idPlano = NEW.idPlano;
    
    -- Insere a assinatura na tabela de estado apropriada
    IF id_assinatura IS NOT NULL THEN
        IF NEW.statuss = 'Pago' THEN
            INSERT INTO Assinatura_Ativa (idAssina) VALUES (id_assinatura);
        ELSEIF NEW.statuss = 'Pendente' THEN
            INSERT INTO Assinatura_Atrasada (idAssina) VALUES (id_assinatura);
        END IF;
    END IF;
END;
//

-- Trigger BEFORE UPDATE on Pagamentos
CREATE TRIGGER before_update_pagamentos
BEFORE UPDATE ON Pagamentos
FOR EACH ROW
BEGIN
    DECLARE id_assinatura INT;
    
    -- Verifica se há uma assinatura associada ao pagamento anterior
    SELECT idAssina INTO id_assinatura FROM Assinaturas WHERE idPlano = OLD.idPlano;
    
    -- Se houver uma assinatura, remove-a das tabelas de estado
    IF id_assinatura IS NOT NULL THEN
        DELETE FROM Assinatura_Ativa WHERE idAssina = id_assinatura;
        DELETE FROM Assinatura_Atrasada WHERE idAssina = id_assinatura;
    END IF;
END;
//

-- Trigger AFTER UPDATE on Pagamentos
CREATE TRIGGER after_update_pagamentos
AFTER UPDATE ON Pagamentos
FOR EACH ROW
BEGIN
    DECLARE id_assinatura INT;
    
    -- Verifica se há uma assinatura associada ao pagamento atualizado
    SELECT idAssina INTO id_assinatura FROM Assinaturas WHERE idPlano = NEW.idPlano;
    
    -- Insere a assinatura na tabela de estado apropriada
    IF id_assinatura IS NOT NULL THEN
        IF NEW.statuss = 'Pago' THEN
            INSERT INTO Assinatura_Ativa (idAssina) VALUES (id_assinatura);
        ELSEIF NEW.statuss = 'Pendente' THEN
            INSERT INTO Assinatura_Atrasada (idAssina) VALUES (id_assinatura);
        END IF;
    END IF;
END;
//

DELIMITER ;

USE trabalho_bd;

-- Drop existing trigger to avoid conflicts
DROP TRIGGER IF EXISTS verificar_assinatura;

DELIMITER //

-- Create a new trigger to check the plan duration date
CREATE TRIGGER verificar_assinatura
AFTER INSERT ON Pagamentos
FOR EACH ROW
BEGIN
    -- Insere idAssina na tabela Assinatura_Inativa se a data atual for maior que a data de duracao do plano associado à assinatura
    INSERT INTO Assinatura_Inativa (idAssina)
    SELECT DISTINCT a.idAssina 
    FROM Assinaturas a
    JOIN Planos p ON a.idPlano = p.idPlano
    WHERE p.duracao < CURDATE()
    AND a.idAssina NOT IN (SELECT idAssina FROM Assinatura_Inativa);
END;
//

DELIMITER ;








