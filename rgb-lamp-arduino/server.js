const express = require('express')
const cors = require('cors')

const SerialPort = require('serialport')

const app = express()
app.use(express.json())
app.use(cors())

const PORT = '/dev/ttyACM3'
const BAUDRATE = 9600

const port = new SerialPort(PORT, {
  baudRate: BAUDRATE,
})

app.post('/', (req, res) => {
  const color = req.body.color
  
  const rgbList = color.match(/\d+/g);

  const r = rgbList[0]
  const g = rgbList[1]
  const b = rgbList[2]

  port.write(Buffer.from(`r${r}, g${g}, b${b}`))
  res.json({ received: `r${r}, g${g}, b${b}` }).status(200)
})

app.listen(3333, () => console.log('Listening on 3333'))
