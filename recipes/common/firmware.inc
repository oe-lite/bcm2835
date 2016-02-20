
# 22/08/2012 firmware; this can be overridden from distro config
RECIPE_FLAGS += "fw_srcrev fw_version"
DEFAULT_USE_fw_srcrev = "branch=master"
DEFAULT_USE_fw_version = "head"

SRC_REV = "${USE_fw_srcrev}"
PV = "${USE_fw_version}"
