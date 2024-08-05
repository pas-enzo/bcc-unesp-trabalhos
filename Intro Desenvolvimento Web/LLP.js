const teams = new Map();

function addTeam() {
  const teamName = prompt("Digite o nome da equipe:");
  if (teamName) {
    teams.set(teamName, []);
    updateTeamList();
  }
}

function removeTeam() {
  const teamName = getSelectedTeam();
  if (teamName) {
    teams.delete(teamName);
    updateTeamList();
  }
}

function addStudentToTeam() {
  const studentName = getSelectedStudent();
  const teamName = getSelectedTeam();
  if (studentName && teamName) {
    const team = teams.get(teamName);
    team.push(studentName);
    updateTeamMembers();
  }
}

function removeStudentFromTeam() {
  const studentName = getSelectedTeamMember();
  const teamName = getSelectedTeam();
  if (studentName && teamName) {
    const team = teams.get(teamName);
    const index = team.indexOf(studentName);
    if (index >= 0) {
      team.splice(index, 1);
      updateTeamMembers();
    }
  }
}

function updateStudentList() {
    const studentList = document.getElementById("students");
    studentList.innerHTML = "";
    for (const student of students) {
      const option = document.createElement("option");
      option.value = student;
      option.text = student;
      studentList.appendChild(option);
    }
  }

function updateTeamList() {
    const teamList = document.getElementById("teams");
    teamList.innerHTML = "";
    for (const teamName of teams.keys()) {
        const option = document.createElement("option");
        option.value = teamName;
        option.text = teamName;
        teamList.appendChild(option);
    }
}
    
function updateTeamMembers() {
    const teamName = getSelectedTeam();
    const teamMembers = document.getElementById("team-members");
    teamMembers.innerHTML = "";
    if (teamName) {
    const team = teams.get(teamName);
    document.getElementById("team-name").textContent = teamName;
    for (const member of team) {
    const li = document.createElement("li");
    li.textContent = member;
    teamMembers.appendChild(li);
    }
    } else {
    document.getElementById("team-name").textContent = "";
    }
}

function showTeamMembers() {
    const teamName = getSelectedTeam();
    if (teamName) {
      const team = teams.get(teamName);
      document.getElementById("team-name").textContent = teamName;
      const teamMembers = document.getElementById("team-members");
      teamMembers.innerHTML = "";
      for (const member of team) {
        const li = document.createElement("li");
        li.textContent = member;
        teamMembers.appendChild(li);
      }
    }
  }
    
function getSelectedStudent() {
    const studentList = document.getElementById("students");
    const selectedOption = studentList.options[studentList.selectedIndex];
    return selectedOption ? selectedOption.value : null;
}
    
function getSelectedTeam() {
    const teamList = document.getElementById("teams");
    const selectedOption = teamList.options[teamList.selectedIndex];
    return selectedOption ? selectedOption.value : null;
}
    
function getSelectedTeamMember() {
    const teamMembers = document.getElementById("team-members");
    const selectedLi = teamMembers.querySelector("li.selected");
    return selectedLi ? selectedLi.textContent : null;
}
    
const students = ["Andre", "Bruno", "Carlos", "Davi", "Emilia", "Frank", "Gustavo", "Heitor", "Iara", "Joao", "Kamila", "Leonardo", "Maria", "Nelson", "Osmar", "Paola", "Quaresma", "Rentainho", "Sofia", "Theo",
                    "Ueverton", "Valeria", "Wallace", "Xavier", "Yan", "Zulmira", "Enzo", "Lucca", "Thiago", "Paulo"];

function initPage() {
    
    updateStudentList();
    
    document.getElementById("add-team").addEventListener("click", addTeam);
    document.getElementById("remove-team").addEventListener("click", removeTeam);
    document.getElementById("students").addEventListener("click", addStudentToTeam);
    document.getElementById("team-members").addEventListener("click", removeStudentFromTeam);
    document.getElementById("teams").addEventListener("click", showTeamMembers);
    updateTeamList();
}
    
window.addEventListener("load", initPage);

