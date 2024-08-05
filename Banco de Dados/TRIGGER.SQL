USE trabalho_bd;

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


DELIMITER //
CREATE TRIGGER verificar_assinatura
AFTER INSERT ON Pagamentos
FOR EACH ROW
BEGIN
    -- Insere idAssina na tabela Assinatura_Inativa se a data atual for maior que dtermin e a assinatura não estiver na tabela Assinatura_Inativa
    INSERT INTO Assinatura_Inativa (idAssina)
    SELECT DISTINCT idAssina 
    FROM Assinaturas 
    WHERE dtermin < CURDATE()
    AND idAssina NOT IN (SELECT idAssina FROM Assinatura_Inativa);
END;
//
DELIMITER ;







