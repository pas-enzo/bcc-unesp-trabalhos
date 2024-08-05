window.onload = function () {
    
    const redSlider = document.getElementById('r');
    const greenSlider = document.getElementById('g');
    const blueSlider = document.getElementById('b');
    const colorBox = document.getElementById('color-box');

    function mudaCor() {
    const redValue = redSlider.value;
    const greenValue = greenSlider.value;
    const blueValue = blueSlider.value;
    colorBox.style.backgroundColor = `rgb(${redValue}, ${greenValue}, ${blueValue})`;
    }

    redSlider.addEventListener('input', mudaCor);
    greenSlider.addEventListener('input', mudaCor);
    blueSlider.addEventListener('input', mudaCor);

};