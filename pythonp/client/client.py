#Base Python client for MEng in IoT Assignment
#consumes data from IoT Gateway
import urllib.request
import numpy as np
import xml.etree.ElementTree as ET
import matplotlib.pyplot as plt
response = urllib.request.urlopen('http://localhost:8080/')
resp = response.read().decode()
time =[]
Temperature=[]
head = ET.fromstring(resp)
for reading in head.findall('reading'):
    time.append(reading.find('time').text)
    Temperature.append(int(reading.find('temperature').text))

plt.style.use('ggplot')
plt.title("Graph between Temperature(y-axis) and Time (x-axis)",fontsize=14, fontweight='bold', color='red', loc='center')
plt.plot(time, Temperature)
plt.xlabel("time  (hours)",fontsize=14, fontweight='bold', color='red')
plt.ylabel("Temperature  (celcius)",fontsize=14, fontweight='bold', color='red');
plt.show()







