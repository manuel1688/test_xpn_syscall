
env LD_PRELOAD=../../../src/xpn_syscall_intercept/xpn_syscall_intercept_create.so:../../../../mxml/libmxml.so.1:$LD_PRELOAD  XPN_CONF=./xpn.conf ./prueba_create /tmp/expand/P1/demo.txt  8

LD_PRELOAD=../../../src/xpn_syscall_intercept/xpn_syscall_intercept_create.so:$LD_PRELOAD  XPN_CONF=./xpn.conf ./prueba_create /tmp/expand/P1/demo.txt  8
