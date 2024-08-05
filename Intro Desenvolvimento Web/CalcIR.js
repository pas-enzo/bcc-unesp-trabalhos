
function calcularImposto() {
        
    const salario = parseFloat(document.getElementById('salario').value);
    const dependentes = parseInt(document.getElementById('dependentes').value);
    
    const faixas = [
        { min: 0, max: 1903.98, taxa: 0 },
        { min: 1903.99, max: 2826.65, taxa: 0.075 },
        { min: 2826.66, max: 3751.05, taxa: 0.15 },
        { min: 3751.06, max: 4664.68, taxa: 0.225 },
        { min: 4664.69, max: Infinity, taxa: 0.275 }
    ];
    
    let imposto = 0;
    let salarioBase = salario - dependentes * 189.59;
    
    for (const faixa of faixas) {
        
        if (salarioBase > faixa.max) {
            imposto += (faixa.max - faixa.min) * faixa.taxa;
        } 
        
        else {
            imposto += (salarioBase - faixa.min) * faixa.taxa;
            break;
        }

        }
    
        document.getElementById('resultado').value = imposto.toFixed(2);
    }    