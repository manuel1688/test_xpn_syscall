INTERCEPT_LOG=logs/intercept.log- \
LD_LIBRARY_PATH=. \
LD_PRELOAD=../../../src/xpn_syscall_intercept/xpn_syscall_intercept.so \
XPN_CONF=./xpn.conf python3 ./p_open.py /tmp/expand/P1/demo.txt 3
