[top]
components : dtmf@Dtmf mcu@mcu 
out : m1Out m2Out m3Out m4Out 
in : dIn 
Link : dIn dIn@dtmf
Link : dOut@dtmf mcuIn@mcu
Link : m1Out@mcu m1Out
Link : m2Out@mcu m2Out
Link : m3Out@mcu m3Out
Link : m4Out@mcu m4Out

[dtmf]
decoding : 00:00:01:000

[mcu]
control : 00:00:05:000


