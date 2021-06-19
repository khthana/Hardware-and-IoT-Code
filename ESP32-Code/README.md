<h4> ตั้งใจจะใช้เป็น Repository สำหรับวิธีการและการใช้งาน ESP32 ตั้งแต่แรกเริ่ม เพื่อจะได้กลับมาทบทวนในภายหลัง</h4>

<h4> สำหรับ Spec ของ ESP-WROOM32 ซึ่งเป็นตัวที่ใช้กันในปัจจุบัน มี Spec ดังนี้ </h4>
<ol>
<li>หน่วยประมวลผล Dual Core Tensilica LX6 ความเร็วสูงสุด 240MHz</li>
<li>RAM ภายใน 520KB</li>
<li>WiFi transceiver B/G/N</li>
<li>Bluetooth  Dual-mode classic และ BLE</li>
<li>Power 2.2 ถึง 3.6V กินกระแสน้อยที่สุด 2.5 µA (ในสถานะ deep sleep)</li>
<li>32 GPIO</li>
<ul>
    <li>10 ช่อง Capacitive Touch</li>
    <li>18 ช่อง Analog-to-Digital converter (ADC)</li>
    <li>3 ช่อง SPI </li>
    <li>3 ช่อง UART </li>
    <li>2 ช่อง I2C </li>
    <li>16 ช่อง ของ PWM</li>
    <li>2 ช่อง Digital-to-Analog Converters (DAC)</li>
    <li>2 ช่อง I2S </li>
 </ul>
 <li>มี Hardware Accelerated Encryption (AES, SHA2, ECC, RSA-4096)</li>
 </ol>    
<h4> สำหรับ Dev. Board ที่ใช้คือ ESP32 ของ DOIT มี PinOut ดังนี้ </h4>
 
<img src="https://raw.githubusercontent.com/playelek/pinout-doit-32devkitv1/master/pinoutDOIT32devkitv1.png" alt="DOIT Pinout">

<br>
<hr>
<h4>การติดตั้ง </h4>
เริ่มต้นก็ต้องติดตั้ง Arduino Core ก่อน โดยไป Download ได้ที่ https://github.com/espressif/arduino-esp32

เมื่อ Download เรียบร้อยแล้ว ก็ให้แตกไฟล์ และนำไปวางที่ C:\Users\[YourName]\Documents\Arduino\hardware\espressif\esp32 
โดยหากไม่มี folder ตั้งแต่ espressif ก็ให้สร้าง folder ขึ้นมาให้ได้ตามข้างต้น โดยให้เปลี่ยนชื่อจาก arduino-esp32-master เป็น esp32 เฉยๆ 

จากนั้นให้เข้าไปที่ C:\Users\[YourName]\Documents\Arduino\hardware\espressif\esp32\tools และรันโปรแกรมชื่อ get.exe 
โดยโปรแกรมนี้จะทำหน้าที่โหลด โปรแกรมและ Library ของ ESP32 

ให้รอจนเสร็จ โปรแกรมจะปิดเอง 

หลังจากนั้นให้ตั้งบอร์ด โดยผมใช้เป็น DOIT ESP32 DEV KIT V.1 แล้วกำหนดพอร์ดให้ถูก จากนั้นทดลองโหลดโปรแกรม Blink ไฟกระพริบเทพลงไป ถ้ามีการกระพริบ ก็แสดงว่าใช้ได้ 

ปล. โปรแกรมทั้งหมด เขียนผ่าน Platform I/O 

https://github.com/khthana/ESP32-Code/blob/master/Blink.cpp

<hr>

<h4>Digital Input : </h4>หลังจากทำไฟกระพริบกันแล้ว ส่วนต่อมาที่มักทำกัน คือ Input เนื่องจากหลายครั้งที่ต้องการการกดปุ่ม <br>
สำหรับการต่อวงจร ผมจะต่อเข้ากับขา 12 ของบอร์ด โดยต่อแบบ Pull Down คือ ปกติจะอ่านได้ Low แต่กดเมื่อไรจะอ่านได้ High <br><br>

สำหรับการต่อ Switch ก็จะคล้ายๆ ในรูป (ในรูปเป็นบอร์ดคนละรุ่น แต่ใช้ขาเดียวกัน)<br><br>

<img src="https://github.com/khthana/ESP32-Code/blob/master/switch.png" alt="Switch"><br>

โปรแกรมก็จะมีดังนี้ <br>

https://github.com/khthana/ESP32-Code/blob/master/SwitchInput.cpp

<hr>

<h4>Interrupt : </h4>ต่อไปก็จะเป็นการ Attach Interrupt โดยใช้ Hardware เดิม คือ ต่อ Switch เข้าที่ขา 12 ของบอร์ด โดยแทนที่จะต้องมาวนลูปอ่าน Switch ก็ใช้ Interrupt แทน <br>

<br> 


https://github.com/khthana/ESP32-Code/blob/master/AttachInterrupt.cpp

<hr>

<h4>Analog Input : </h4> ความสามารถที่ Upgrade มาจาก ESP8266 มาก ก็คือ Analog to Digital Converter หรือ ADC โดยมีมาให้ถึง 8 Channel 
โดยจะอยู่ที่ขา ดังนี้ channel 0 = GPIO36, channel 1 = GPIO37, channel 2 = GPIO38, channel 3 = GPIO39, channel 4 = GPIO32, channel 5 = GPIO33, channel 6 = GPIO34, channel 7 = GPIO35

และความละเอียดก็มากขึ้นด้วย โดยมีให้ถึง 0-4096 ระดับ <br><br>

<img src="https://github.com/khthana/ESP32-Code/blob/master/ADC.png" alt="ADC"><br>

สำหรับโปรแกรมนี้ก็จะใช้ GPIO34

https://github.com/khthana/ESP32-Code/blob/master/ADC.cpp

<hr>

<h4>PWM : </h4>ใน ESP32 จะต่างจาก Arduino หรือ ESP8266 เพราะไม่มีคำสั่ง AnalogWrite ให้ใช้ แต่จะใช้ไลบรารีชื่อ LEDC โดยมีรูปแบบคำสั่งดังนี้ <br><br>


void ledcSetup(byte channel, double freq, byte resolution_bits);

channel คือ หมายเลขของ Timer ที่อยู่ภายใน ESP32 โดยมีตั้งแต่ 0-15 
freq คือ ความถี่ที่จะให้ Timer สร้างให้ โดยใช้เป็นความถี่ฐาน 
resolution_bits คือ ค่าความละเอียด ใช้ได้ตั้งแต่ 0-15 (บิต) หากจะใช้เท่ากับ Arduino ก็ใช้ 8 บิต ซึ่งจะต้องสัมพันธ์กับคำสั่ง ledcWrite ด้วย เช่น จากโปรแกรมจะใช้ 13 บิต ดังนั้นในคำสั่ง ledcWrite จะใช้ค่าสูงสุด 8096 โดยค่านี้จะเป็นความละเอียดของ Duty Cycle ที่สามารถใช้ได้ 

อีกฟังก์ชันที่ใช้ คือ 
 
void ledcAttachPin(int pin, byte channel);

จะใช้ในการเชื่อมขาของ ESP32 เข้ากับ Timer (แปลว่าจะใช้ขาอะไรก็ได้) นอกจากนั้น Timer 1 ตัวจะเชื่อมกับหลายขาก็ได้ด้วย 

ฟังก์ชันสุดท้าย คือ 

void ledcWrite(byte channel, int duty);

จะใช้ในการสั่งคลื่นให้ออกทางขา โดยสามารถกำหนด Duty Cycle ได้ (ต้องสัมพันธ์กับ resolution) <br>

https://github.com/khthana/ESP32-Code/blob/master/PWM.cpp

<hr>
<h4>Tone : </h4>
เนื่องจากไลบรารีของ ESP32 ไม่มีฟังก์ชัน tone (อีกแล้วครับท่าน) ดังนั้นจึงต้องนำ PWM มาใช้ด้วย โดยในการนี้เราจะ Fix Duty Cycle และเปลี่ยนเฉพาะความถี่ โดยเขาว่ากันว่า Duty Cycle ที่เหมาะสมคือ 5% โดยเขาทำเป็นฟังก์ชัน ledcWriteTone(channel, freq); มาให้ โดยตัวอย่างโปรแกรมมีดังนี้
<br><br>

https://github.com/khthana/ESP32-Code/blob/master/Tone.cpp


<hr>
<h4>DAC : </h4>

DAC (Digital to Analog Converter) หรือความสามารถในการสร้างสัญญาณ Analog เป็นความสามารถใหม่ที่มีใน ESP32 โดยไม่มีใน Arduino และ ESP8266 ซึ่งจริงๆ แล้ว DAC มีประโยชน์หลายอย่าง เช่น สามารถนำไปใช้ในการสร้างเสียงที่คล้ายกับเสียงจริงได้ หรือ เอาไปสร้าง Function Generator ได้ หรืออื่นๆ อีกมากมาย <br>

DAC ใน ESP32 ได้ให้มา 2 ช่อง หรือ 2 ขา คือ ขา GPIO25 และ GPIO26 โดยมีระดับสัญญาณ 8 บิต ดังนั้นสัญญาณที่สร้างขึ้นก็อาจจะไม่ smooth มากนัก แต่ข้อจำกัดคือ กระแสอาจไม่มากนัก 

โปรแกรมตัวอย่างเป็นโปรแกรม Function Generator คือ โปรแกรมสำหรับสร้างรูปคลื่น โดยเป็นโปรแกรมสำหรับสร้าง sine wave โดยถ้าต้องการรูปคลื่นแบบอื่น ก็สามารถเปลี่ยนได้โดยเอา code จาก comment มาเปลี่ยนแทน โดยตัวอย่างโปรแกรมมีดังนี้

https://github.com/khthana/ESP32-Code/blob/master/DAC_Basic.cpp<br><br>
https://github.com/khthana/ESP32-Code/blob/master/DAC_Advance.cpp


<hr>
<h4>DHT22 : </h4>

เป็นเซ็นเซอร์สำหรับตรวจวัดอุณหภูมิและความชื้นยอดนิยม เรียกได้ว่าถ้ามีสอนเกี่ยวกับ IoT ต้องมี DHT22 มาเลย ในโปรแกรมนี้จะต่อที่ขา 12 

<img src="https://github.com/khthana/ESP32-Code/blob/master/DHT22.png" alt="DHT22"><br>

https://github.com/khthana/ESP32-Code/blob/master/DHT22.cpp

<hr>
<h4>OLED : </h4>
เป็นจอแสดงผลขนาดเล็ก โดยมีความละเอียด 128x64 การติดต่อจะใช้ I2C สามารถแสดงผลได้ทั้ง Text และ กราฟิก 
<br><br>

<img src="https://github.com/khthana/ESP32-Code/blob/master/OLED.png" alt="OLED"><br>

โปรแกรมตัวอย่างจะมีทั้งหมด 3 โปรแกรม <br>
โปรแกรมแรกจะเป็นโปรแกรมง่ายๆ แสดงข้อความอย่างเดียว (ปล. ต้องไปแก้ไฟล์ Include โดยแก้ความละเอียดเป็น 128x64) <br>

https://github.com/khthana/ESP32-Code/blob/master/OLED_text.cpp

โปรแกรมที่ 2 เป็นโปรแกรมแสดงกราฟิกแบบง่ายๆ คือวาด สี่เหลี่ยม วงกลม <br>

https://github.com/khthana/ESP32-Code/blob/master/OLED_Graphic.cpp

สำหรับโปรแกรมที่ 3 เป็นโปรแกรม demo ของ OLED มีความซับซ้อนพอสมควร แสดงทุกฟังก์ชันที่สามารถทำได้ <br>

https://github.com/khthana/ESP32-Code/blob/master/OLED_Graphic2.cpp

<hr>
<h4>TCP Client : </h4>
การเชื่อมต่อผ่านเครือข่าย ถือเป็นจุดขายที่สำคัญ (ตั้งแต่ ESP8266 ผู้พี่แล้ว) ซึ่งทำให้บอร์ดเล็ก สามารถทำตัวเป็น Client ของ WiFi ได้ โดยโปรแกรมนี้จะแสดงการเชื่อมต่อกับ TCP Server ต่างๆ (จะเป็นอะไรก็ได้) โดยในโปรแกรมนี้เราจะใช้โปรแกรม Hercules ช่วยในการทำงานเป็น Server โดยโปรแกรมนี้จะ Connect WiFi จากนั้นจะติดต่อกับ Server พร้อมกับส่งคำว่า Hello ไปเรื่อย แต่ถ้า Server ส่งอะไรมา ก็นำมาแสดงที่ Serial Monitor<br><br>

โปรแกรมนี้จะมีการแสดงผลผ่าน OLED ซึ่งไม่ใช้ก็ได้ (ให้ Comment ออก) <br><br>

https://github.com/khthana/ESP32-Code/blob/master/WiFi_Client.cpp

<hr>
<h4>TCP Server : </h4>
โปรแกรมนี้จะให้ ESP32 ทำตัวเป็น TCP Server แต่โปรแกรมจะยาวนิดหน่อย โดยจะมีส่วนที่แสดง IP, Subnet Mark, Gateway นอกจากนั้นยังมีส่วนที่แสดง Channel ที่ Connect, ความแรงของสัญญาณ (RSSI), DNS Lookup, การสแกนหา Access Point ที่มองเห็นและความแรงในแต่ละ Access Point จากนั้นจะเข้าสู่การเป็น Server โดยจะรอรับ Connection <br> 

โปรแกรมนี้ จะรอรับ Connection ได้ 2 IP <br> 

https://github.com/khthana/ESP32-Code/blob/master/WiFi_Server.cpp

<hr>
<h4>WiFi AP Mode : </h4>

นอกจาก ESP32 จะทำงานในโหมด Station คือ Connect กับ Access Point อื่นๆ แล้ว ยังสามารถทำงานในโหมด AP คือทำตัวเป็น Access Point เพื่อให้ Client มาเกาะ โดยจะมี 2 โปรแกรม คือ ส่วนที่เป็น Server และส่วนที่เป็น Client โดยค่า IP ของ AP ที่เป็น Default คือ 192.168.4.1 

https://github.com/khthana/ESP32-Code/blob/master/AP_Mode_Server.cpp<br>

https://github.com/khthana/ESP32-Code/blob/master/AP_Mode_Client.cpp

<hr>
<h4>Thinkspeak : </h4>
ถ้าจะไปทาง IoT ส่วนใหญ่น่าจะมีสักครั้งที่ลองกับ Thinkspeak ทั้งนี้เพราะมันง่าย Thinkspeak เป็นบริการ IoT คลาวด์ในแบบ Paas (Platform as a Services) โดยมีความสามารถเก็บข้อมูลแบบ Real-time แสดงข้อมูลเป็นกราฟได้ สามารถส่งข้อมูลและเรียกดูจากที่ใดก็ได้ในโลก แล้วยังสามารถดึงข้อมูลไปแสดงที่เว็บของเราได้ด้วย โดยมีบริการทั้งแบบฟรี และ เสียเงิน

ก่อนอื่นก็ไปสมัคร โดยเข้าไปที่เว็บ https://thingspeak.com/ สร้าง Account เสร็จแล้วล็อกอิน จากนั้นเลือก New Channel โดยในโปรแกรมเราจะต่อกับ DHT22 ดังนั้นก็ให้สร้าง Channel สำหรับเก็บค่าอุณหภูมิ 
<br><br>
<img src="https://github.com/khthana/ESP32-Code/blob/master/Thingspeak.jpg" alt="Thingspeak">
<br>
จากนั้นให้ไปที่ API Keys แล้ว copy API Key เก็บเอาไว้ ทั้งสองตัว สำหรับโปรแกรมนี้จะเป็นโปรแกรมที่อ่านค่าจาก DHT22 แล้วส่งมาที่ Thingspeak ซึ่งหากจะเอาโปรแกรมไปใช้ ก็ให้เปลี่ยนค่า Write API Key เป็นของตัวเอง และกำหนด ssid/password แล้วก็รัน มันจะส่งข้อมูลทุก 5 วินาที ถ้าจะให้ส่งช้าหรือเร็วกว่านี้ ก็เปลี่ยนที่ delay 

เสร็จแล้วก็ไปเช็คที่เว็บ Thingspeak ว่ามีข้อมูลขึ้นหรือไม่ ถ้ามีข้อมูลก็แสดงว่าโปรแกรมทำงานได้ถูกต้อง <br>

https://github.com/khthana/ESP32-Code/blob/master/Thingspeak.cpp

<hr>
<h4>Blynk : </h4>
Blynk เป็น Platform ที่ทำให้เราสามารถเชื่อมต่ออุปกรณ์เช่น Arduino, ESP8266 หรือ ESP32 กับ Mobile App ได้ง่าย โดยไม่ต้องพัฒนาโปรแกรมเอง ส่วนประกอบของ Blynk มี 3 ส่วนได้แก่ 1) Mobile App สำหรับควบคุมและดูข้อมูล 2) Cloud Service สำหรับเก็บข้อมูลจากอุปกรณ์ 3) Library สำหรับเขียนโปรแกรมสำหรับอุปกรณ์เพื่อเชื่อมต่อกับ Blynk

ก่อนอื่นก็ต้องติดตั้งโปรแกรม Blynk แล้วสร้าง Project ตั้งชื่อ แล้วเลือกบอร์ดเป็น ESP32 จากนั้น Blynk จะส่ง Token มาทาง E-Mail แล้วก็ต้องติดตั้ง Library Blynk ใน IDE ด้วยนะครับ 

จากนั้นก็โหลดโปรแกรมต่อไปนี้ลงใน ESP32 

https://github.com/khthana/ESP32-Code/blob/master/Blynk.cpp

จากนั้นก็ Config ที่ Blynk ตามใจชอบ หากต้องการทดสอบ ให้สร้าง widget ที่เป็นปุ่มมา 1 ปุุ่ม โดยตั้ง GPIO ให้ตรงกับไฟ LED แล้วกด Play จะพบว่าสามารถกดปุ่มเพื่อปิดเปิด LED บนบอร์ดได้ 

หากจะส่งค่าไปที่โปรแกรมบนมือถือ ให้เพิ่ม Gauge มา 2 อัน โดยกำหนดให้เป็น Input ให้เป็น Virtual ตั้งชื่อเป็น Temp และ Humidity ก็จะเห็นข้อมูลจาก DHT22 ส่งขึ้นไปแสดงใน Widget 

<hr>
<h4>Firebase : </h4>
Firebase เป็นฐานข้อมูลออนไลน์ของ google รูปแบบการใช้งานจะเป็นแบบ NoSQL การเก็บข้อมูลจะเป็น JSON สามารถเขียนโปรแกรมเชื่อมต่อด้วยภาษา Python, PHP, ฯลฯ และสามารถใช้ REST API ในการติดต่อได้ ดังนั้นเราสามารถเขียนโปรแกรมให้ ESP32 ให้ส่งข้อมูลขึ้นไปเก็บบน Firebase เพื่อเอาไปทำอย่างอื่นต่อไป 

ก่อนอื่นให้เข้าไปที่ https://firebase.google.com/ แล้วล็อกอิน

จากนั้นเลือก Add Project ตั้งชื่อ เลือกประเทศ แล้ว Create Project ก็จะเข้ามาที่หน้านี้

<img src="https://github.com/khthana/ESP32-Code/blob/master/Firebase1.jpg" alt="Firebase"><br>

ไปที่ Project Setting (รูปเฟือง) ไปต่อที่หน้า Service Accounts แล้วเลือก Database Secrets

<img src="https://github.com/khthana/ESP32-Code/blob/master/Firebase2.jpg" alt="Firebase"><br>

ให้คัดลอกคีย์เอาไว้ ตรงบริเวณที่เป็น จุดจุด ให้กดที่ show ก่อน เพื่อให้ยกเลิกการซ่อน 

เสร็จแล้วให้คลิกที่ Develop -> Database แล้วคลิก Get Started ที่ Realtime Database เลือก Start in Test Mode แล้วกด Enable จะได้หน้าจอนี้ 

<img src="https://github.com/khthana/ESP32-Code/blob/master/Firebase3.jpg" alt="Firebase"><br>

เอาละครับคราวนี้ก็กลับไปที่ ESP32 แล้วติดตั้ง Library ชื่อ 


















