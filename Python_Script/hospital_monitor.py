import serial
import time
import matplotlib.pyplot as plt
import matplotlib.animation as animation
from collections import deque

# সেটিংস
SERIAL_PORT = 'COM4'  
BAUD_RATE = 9600

# সিরিয়াল কানেকশন
try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    print(f"Connected to {SERIAL_PORT}")
    time.sleep(2)
except Exception as e:
    print(f"Error: {e}")
    exit()

# ডাটা স্টোরেজ
max_points = 100
pulse_data = deque([0] * max_points, maxlen=max_points)
temp_data = deque([0] * max_points, maxlen=max_points)

# গ্রাফ উইন্ডো সেটআপ
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 8))
plt.subplots_adjust(hspace=0.5)

def animate(i):
    try:
        if ser.in_waiting > 0: # ডাটা আসলে তবেই কাজ করবে
            line = ser.readline().decode('utf-8').strip()
            
            # কনসোলে প্রিন্ট করো (Debug)
            print(f"Received: {line}") 
            
            if line:
                parts = line.split(',')
                if len(parts) == 2:
                    pulse_val = int(parts[0])
                    temp_val = float(parts[1])
                    
                    pulse_data.append(pulse_val)
                    temp_data.append(temp_val)
                    
                    # Pulse Graph
                    ax1.clear()
                    ax1.plot(pulse_data, color='blue')
                    ax1.set_title(f"Heart Rate: {pulse_val}", color='blue')
                    ax1.set_ylim(0, 1024)

                    # Temp Graph
                    ax2.clear()
                    ax2.plot(temp_data, color='red')
                    ax2.set_title(f"Temperature: {temp_val} C", color='red')
                    ax2.set_ylim(20, 50)
    except Exception as e:
        pass

# ওয়ার্নিং ফিক্স করার জন্য cache_frame_data=False যোগ করা হলো
ani = animation.FuncAnimation(fig, animate, interval=50, cache_frame_data=False)
plt.show()

ser.close()