const visor = document.querySelector('.visor');
const botoes = document.querySelectorAll('.botao');

let valorVisor = '';

botoes.forEach(botao => {
  botao.addEventListener('click', () => {
    const valorBotao = botao.innerHTML;

    if (valorBotao === '=') {
      valorVisor = eval(valorVisor);
      visor.innerHTML = valorVisor;
    } else if (valorBotao === 'C') {
      valorVisor = '';
      visor.innerHTML = '';
    } else {
      valorVisor += valorBotao;
      visor.innerHTML = valorVisor;
    }
  });
});