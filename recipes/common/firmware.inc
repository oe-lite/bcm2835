
# 22/08/2012 firmware; this can be overridden from distro config
RPIFW_SRCREV ?= "branch=master"
RPIFW_DATE ?= "head"


SRC_REV = "${RPIFW_SRCREV}"
PV = "${RPIFW_DATE}"
