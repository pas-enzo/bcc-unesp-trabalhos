const bancoSelect = document.querySelector('.esq select');
const aulaSelect = document.querySelector('.dir select');
const setaEsq = document.querySelector('.botaoSetaEsq button');
const setaDir = document.querySelector('.botaoSetaDir button');
const btnClear = document.querySelector('.clear button');
const contador = document.querySelector('.contador');

let count = 0;

setaEsq.addEventListener('click', () => {
  const itemSelecionado = bancoSelect.options[bancoSelect.selectedIndex];
  aulaSelect.add(itemSelecionado);
  bancoSelect.remove(bancoSelect.selectedIndex);
  count++;
  contador.innerHTML = count;
});

setaDir.addEventListener('click', () => {
  const itemSelecionado = aulaSelect.options[aulaSelect.selectedIndex];
  bancoSelect.add(itemSelecionado);
  aulaSelect.remove(aulaSelect.selectedIndex);
  count--;
  contador.innerHTML = count;
});

btnClear.addEventListener('click', () => {
  const listaBanco = document.querySelector('.lista-banco');
  const listaAula = document.querySelector('.lista-aula');
  while (listaAula.options.length > 0) {
    listaBanco.add(listaAula.options[0]);
  }
  count = 0;
  contador.innerHTML = count;
});
