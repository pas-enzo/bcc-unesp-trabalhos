const form = document.querySelector("#form");
const divColocaDados = document.querySelector("#coloca-dados");
const botaoConsulta = document.querySelector("#botao-consulta");
const divColocaSelect = document.querySelector("#coloca-select");

form.addEventListener("submit", (e) => {
  e.preventDefault();
  const usuario = {
    id: document.querySelector("#id").value,
    nome: document.querySelector("#nome").value,
    email: document.querySelector("#email").value,
    curso: document.querySelector("#curso").value,
  };
  console.log(usuario);
  fetch("http://localhost:8081/aluno/:id", {
    method: 'POST',
    headers: {
      "Content-Type": "application/json"
    },
    body: JSON.stringify(usuario)
  })
  .then(response => {
    console.log(response);
    return response.json();
  })
  .then(data => {
    console.log(data);
  });
});

botaoConsulta.addEventListener("click", (e) => {
  fetch("http://localhost:8081/aluno", {
    method: 'GET',
    headers: {
      "Content-Type": "application/json"
    },
  })
  .then(response => {
    console.log(response);
    return response.json();
  })
  .then(data => {
    const p = document.createElement("p");
    p.innerHTML = JSON.stringify(data);
    divColocaDados.innerHTML = '';
    divColocaDados.appendChild(p);
    console.log(data);
  });

  excluirDado();
});

function excluirDado() {
  fetch('http://localhost:8081/aluno')
    .then((response) => {
      console.log(response);
      return response.json();
    })
    .then((data) => {
      let json = [];
      const botaoRemover = document.createElement("input");
      botaoRemover.type = "submit";
      botaoRemover.value = "Remover Dado";
      const selectDados = document.createElement("select");
      console.log(data);
      json = JSON.parse(JSON.stringify(data));
      let cont = 0;
      json.forEach(dado => {
        selectDados.options[cont++] = new Option(dado.nome, dado.id);
      });
      divColocaSelect.innerHTML = '';
      divColocaSelect.appendChild(selectDados);
      divColocaSelect.appendChild(botaoRemover);
      botaoRemover.addEventListener("click", (e) => {
        const url = "http://localhost:8081/apaga/" + selectDados.options[selectDados.selectedIndex].value.toString();
        fetch(url, {
            method: 'DELETE',
          })
          .then((response) => {
            console.log(response);
            return response.json();
          })
          .then((data) => {
            console.log(data);           
          })
          .catch((error) => {
            console.log(error);
          });
      });
    })
    .catch((error) => {
      console.log(error);
    });
}