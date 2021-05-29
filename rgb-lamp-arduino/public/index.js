function paintBg() {
  let rgbValues = document.querySelector('#rgb-values')
  let colorInput = document.querySelector('#colorInput')
  let area = document.querySelector('#area')

  const colorCode = getRGB(colorInput.value)
  
  rgbValues.innerHTML = colorCode
  area.style.background = colorCode

  submit()
}

function getRGB(colorHexa) {
  const r = parseInt(colorHexa.substr(1,2), 16)
  const g = parseInt(colorHexa.substr(3,2), 16)
  const b = parseInt(colorHexa.substr(5,2), 16)

  return(`rgb(${r}, ${g}, ${b})`)
}

function submit() {
  const color = document.querySelector('#rgb-values').innerHTML

  fetch('http://localhost:3333', {
    method: 'post',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({ color: color }),
  })
}