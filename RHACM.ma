[top]
components : gsm@Gsm Relay1@Relay1 Relay2@Relay2 Relay3@Relay3 soundch@Soundch control 
out : r1Out r2Out r3Out scOut 
in : callIn 
Link : gsmOut@gsm dIn@control
Link : m4Out@control scIn@soundch
Link : m1Out@control r1In@Relay1
Link : m2Out@control r2In@Relay2
Link : m3Out@control r3In@Relay3
Link : callIn callIn@gsm
Link : scOut@soundch scOut
Link : r3Out@Relay3 r3Out
Link : r2Out@Relay2 r2Out
Link : r1Out@Relay1 r1Out

[gsm]
receiving : 00:00:02:000

[Relay1]
switching : 00:00:00:000

[Relay2]
switching : 00:00:00:000

[Relay3]
switching : 00:00:00:000

[soundch]
recording : 00:00:10:000

[control]
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



