document.getElementById("myForm").addEventListener("submit", function(event) {
    event.preventDefault();
  
    const formData = new FormData(this);
  
    const jsonObject = {};
    for (const [key, value] of formData.entries()) {
      jsonObject[key] = value;
    }
    const jsonString = JSON.stringify(jsonObject);
  
    alert(jsonString);
  });