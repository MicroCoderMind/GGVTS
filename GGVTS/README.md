GPS-GSM-Vehicle-Tracking-System/Customer Requirement
@CreativeGroup8592
CreativeGroup8592 Create Customer Requirement
Latest commit f4ac700 12 seconds ago
History
1 contributor
23 lines (23 sloc) 1.44 KB
GPS/GSM Vehicle Tracking System
Vehicle Name: Royal Enfield Classic 350 ABS
Development Phase 1
Customer Requirements:
1.	Module shall send vehicle location continuously on owner’s mobile with help of GSM
2.	Module shall send vehicle location whenever required on owner’s mobile with the help of GSM.
3.	Frequency of messages can be set to:
3.a.	0 minutes ( Keep sending location Continuously)
3.b.	5 minutes ( Send location after every 5 minutes)
3.c.	10 minutes (Send location after every 10 minutes)
3.d.	20 minutes (Send location after every 20 minutes)
3.e.	30 minutes (Send location after every 30 minutes)
3.f.	24 hours (Send location after every 24 hours)
4.	User should be able to switch off system with help of GSM.
4.a.	Software has to use value 255 to put itself on hibernate when received from user through GSM module.
5.	Software should have facility so that when user wanted to park vehicle for long time like more than 48 hours, In this period if vehicle’s location changed then user should get this information.(A pin of microcontroller can be used for this)*
6.	User/Owner should be able to set frequency of messages he/she wants to get on mobile.
7.	Connections of module should be in this way that, each major component should get separate power supply.
8.	In case of emergency power down, before getting off system should inform user about emergency.
9.	Emergency situations include
9.a.	sudden shutdown
9.b.	Forcefully Plug out
9.c.	Manually override





*: When a bike is parked for long duration, user can send message to GSM module to keep system in park(hibernate) mode which will set a variable i.e PARK_MODE to ON i.e. 1. and it will be continously compared with that particular pin of micro controller. In case of security breach i.e. if someone start bike then a mismatch between varibale(PARK_MODE) and pin of microcontroller is happened and a message is sent to user about security breach.
