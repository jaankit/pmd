lib_LTLIBRARIES = libpmdclient.la

libpmdclient_la_CPPFLAGS = \
    -I$(top_srcdir)/include \
    -I$(top_srcdir)/idl \
    @LW_INCLUDES@

libpmdclient_la_SOURCES = \
    gssapi_creds_plugin.c \
    fwmgmt_api.c \
    fwmgmt_cstub.c \
    pkgmgmt_api.c \
    rpc.c \
    rpcmem.c \
    rpcpkgmisc.c \
    pkgmgmt_cstub.c \
    pmd_cstub.c \
    netmgmt_cstub.c \
    netmgr_api.c \
    rolemgmt_api.c \
    rolemgmt_cstub.c \
    usermgmt_api.c \
    usermgmt_cstub.c \
    usermgmt_rpc_misc.c \
    privsepd_api.c \
    privsepd_cstub.c \
    pkgmgmt_privsep_cstub.c \
    netmgmt_privsep_cstub.c \
    fwmgmt_privsep_cstub.c \
    usermgmt_privsep_cstub.c

if ENABLE_DEMO
demo_cstub.c:
	cp ../idl/demo_cstub.c .
	cp ../idl/demo_privsep_cstub.c .

    libpmdclient_la_SOURCES += demo_cstub.c
    libpmdclient_la_SOURCES += demo_privsep_cstub.c
    libpmdclient_la_SOURCES += demo_api.c
endif

fwmgmt_cstub.c:
	cp ../idl/fwmgmt_cstub.c .

pkgmgmt_cstub.c:
	cp ../idl/pkgmgmt_cstub.c .

pmd_cstub.c:
	cp ../idl/pmd_cstub.c .

netmgmt_cstub.c:
	cp ../idl/netmgmt_cstub.c .


rolemgmt_cstub.c:
	cp ../idl/rolemgmt_cstub.c .

usermgmt_cstub.c:
	cp ../idl/usermgmt_cstub.c .

privsepd_cstub.c:
	cp ../idl/privsepd_cstub.c .

pkgmgmt_privsep_cstub.c:
	cp ../idl/pkgmgmt_privsep_cstub.c .

netmgmt_privsep_cstub.c:
	cp ../idl/netmgmt_privsep_cstub.c .

fwmgmt_privsep_cstub.c:
	cp ../idl/fwmgmt_privsep_cstub.c .

usermgmt_privsep_cstub.c:
	cp ../idl/usermgmt_privsep_cstub.c .

CLEANFILES = \
    demo_cstub.c \
    demo_privsep_cstub.c \
    fwmgmt_cstub.c \
    pkgmgmt_cstub.c \
    pmd_cstub.c \
    netmgmt_cstub.c \
    usermgmt_cstub.c \
    privsepd_cstub.c \
    pkgmgmt_privsep_cstub.c \
    netgmgmt_privsep_cstub.c \
    fwgmgmt_privsep_cstub.c \
    usergmgmt_privsep_cstub.c \
    rolemgmt_cstub.c \
    rpmostree_cstub.c

libpmdclient_la_LIBADD =  \
    @top_builddir@/common/libcommon.la \
    @DCERPC_LIBS@ \
    @LWBASE_LIBS@ \
    -lpthread \
    -llwbase_nothr

libpmdclient_la_LDFLAGS= \
    @LW_LDFLAGS@ \
    @DCERPC_LDFLAGS@
