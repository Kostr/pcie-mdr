# Description

This package provides a dedicated IPMI blob to receive PCIe information from host and an application that parses it and publishes on the D-Bus.

Software to actually send PCIe device information from Host to BMC can be found in the [pcie_blob_transfer](https://github.com/Kostr/pcie_blob_transfer) repository.

# Recipe example

`pcie-mdr` is not a part of the openbmc software stack, so you have to add the recipe manually.

Create the file `meta-phosphor/recipes-phosphor/pcie/pcie-mdr_git.bb` with the following content:
```
LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE;md5=e3fc50a88d0a364313df4b21ef20c29e"

DEPENDS += " \
    boost \
    systemd \
    sdbusplus \
    phosphor-logging \
    phosphor-ipmi-blobs \
    "

SRC_URI = "git://github.com/Kostr/pcie-mdr.git;protocol=https;branch=master"

PV = "1.0+git${SRCPV}"
SRCREV = "e291a6e688c77aee443555a00f8a39216d7295ee"

S = "${WORKDIR}/git"

SYSTEMD_SERVICE:${PN} += "pcie-mdrv2.service"

inherit cmake pkgconfig systemd
inherit obmc-phosphor-ipmiprovider-symlink

FILES:${PN}:append = " ${libdir}/ipmid-providers/lib*${SOLIBS}"
FILES:${PN}:append = " ${libdir}/blob-ipmid/lib*${SOLIBS}"
FILES:${PN}-dev:append = " ${libdir}/ipmid-providers/lib*${SOLIBSDEV}"

BLOBIPMI_PROVIDER_LIBRARY += "libpciestore.so"
```

Change `SRCREV` to point to the latest commit in the `pcie-mdr` repository.
