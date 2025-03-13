#!/usr/bin/env python3

message = {
    "id":"0x100",
    "signals":[
        {"name":"temperature",                   "type":"float",    "length":10, "comment":"the ambient temperature"},
        {"name":"humidity",                      "type":"uint8_t",  "length":7,  "comment":"the ambient humidity percentage"},
        {"name":"dht_sensor_status",             "type":"uint8_t",  "length":2,  "comment":"the dht sensor status"},
        {"name":"flow_rate",                     "type":"uint16_t", "length":9,  "comment":"the flow rate in milliliter per second"},
        {"name":"flow_meter_sensor_status",      "type":"uint8_t",  "length":2,  "comment":"the flow meter sensor status"},
        {"name":"light_intensity",               "type":"uint8_t",  "length":7,  "comment":"the light intensity percentage"},
        {"name":"light_intensity_sensor_status", "type":"uint8_t",  "length":2,  "comment":"the light intensity sensor status"},
        {"name":"water_level",                   "type":"uint8_t",  "length":7,  "comment":"the water level percentage"},
        {"name":"water_level_sensor_status",     "type":"uint8_t",  "length":2,  "comment":"the water level sensor status"},
        {"name":"soil_moisture",                 "type":"uint8_t",  "length":7,  "comment":"the soil moisture percentage"},
        {"name":"soil_moisture_sensor_status",   "type":"uint8_t",  "length":2,  "comment":"the soil moisture sensor status"}
    ]
}

maxlen: int = 0
namelen = 0
typelen = 0
lengthlen = 6
desclen = 0
commentlen = 0
names = []
types = []
lengths = []
comments = []

for signal in message.values():
    if type(signal)==(list):
        for lst in signal:
            if len(str(list(lst.values())))>maxlen:
                maxlen=len(str(lst))

for signal in message.values():
    if type(signal)==(list):
        for lst in signal:
            #print(list(lst.values()))
            for key,val in lst.items():
                if key == "name":
                    if len(str(val))>namelen:
                        namelen=len(str(val))
                    names.append(val)
                if key == "type":
                    if len(str(val))>typelen:
                        typelen=len(str(val))
                    types.append(val)
                if key == "length":
                    if len(str(val))>lengthlen:
                        lengthlen=len(str(val))
                    lengths.append(val)
                if key == "comment":
                    if len(str(val))>commentlen:
                        commentlen=len(str(val))
                    comments.append(val)

print("Signal", " "*(namelen-5), "| Type", " "*(typelen-3), "| Length | Description","\n", "-"*maxlen, sep='')

iteration = 0
for row in message['signals']:
    print(
        names[iteration], " "*(namelen-len(names[iteration])), " | ",
        types[iteration], " "*(typelen-len(types[iteration])), " | ",
        str(lengths[iteration]).center(lengthlen)," | ",
        comments[iteration], " "*(commentlen-len(comments[iteration])), sep='')
    iteration += 1
