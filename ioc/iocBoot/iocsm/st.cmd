export EPICS_CAS_SERVER_PORT=5068
export EPICS_CAS_BEACON_PORT=5067
export EPICS_CAS_AUTO_BEACON_ADDR_LIST=NO
export EPICS_CAS_BEACON_ADDR_LIST="127.0.0.1"

#!../../bin/linux-x86_64/sm

#- You may have to change sm to something else
#- everywhere it appears in this file

< envPaths

cd "${TOP}"

## Register all support components
dbLoadDatabase "dbd/sm.dbd"
sm_registerRecordDeviceDriver pdbbase


epicsEnvSet("STREAM_PROTOCOL_PATH","/home/blctrl/epics/xiantest/blcg-e625-ioc/ioc/db")
drvAsynIPPortConfigure("P1","192.168.1.254:4001 TCP",0,0,0)
drvAsynIPPortConfigure("P2","192.168.1.254:4002 TCP",0,0,0)

dbLoadTemplate("db/pi-e816.subs")

cd "${TOP}/iocBoot/${IOC}"
iocInit

## Start any sequence programs
#seq sncxxx,"user=blctrl"
