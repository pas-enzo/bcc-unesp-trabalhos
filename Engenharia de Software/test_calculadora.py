from calculadora import Calculadora

def test_soma():
  # Arrange
  v1 = 2
  v2 = 5
  esperado = 7
  calc = Calculadora()

  # Act
  resultado = calc.soma(v1, v2);

  # Assert
  assert resultado == esperado