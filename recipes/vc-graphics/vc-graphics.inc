DESCRIPTION = "Graphics libraries for BCM2835."
LICENSE = "Proprietary"

PROVIDES_${PN} = "libgles2 libegl"

include ../common/firmware.inc

SRC_URI = "git://github.com/raspberrypi/firmware.git;protocol=git;${SRC_REV}\
           file://egl.pc \
           file://vchiq.sh"

S = "${SRCDIR}/firmware/${VCDIR}"

inherit library pkgconfig sysvinit

RECIPE_FLAGS += "hardfp softfp"

do_install () {
  install -d ${D}${bindir}
  cp -R bin/* ${D}${bindir}

  install -d ${D}${sbindir}
  cp -R sbin/* ${D}${sbindir}

  install -d ${D}${libdir}
  cp -R lib/* ${D}${libdir}

  install -d ${D}${includedir}
  cp -R include/* ${D}${includedir}

  install -d ${D}${libdir}/pkgconfig
  install -m 0644 ${SRCDIR}/egl.pc ${D}${libdir}/pkgconfig/

  sysvinit_install_script ${SRCDIR}/vchiq.sh
}

# These are proprietary binaries generated elsewhere so don't check ldflags
INSANE_SKIP_${PN} = "ldflags"

RECIPE_FLAGS += "vc_graphics_sysvinit_start"
DEFAULT_USE_vc_graphics_sysvinit_start = "03"

FILES_${PN} = "${bindir}/* \
               ${sbindir}/* \
               ${libdir}/lib*.so \
               ${sysconfdir}/init.d"
FILES_${PN}-dev = "${libdir}/pkgconfig \
                   ${includedir} \
		   ${libdir}/lib*.a"
