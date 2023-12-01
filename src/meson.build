cpp_args_pcie = boost_args

executable(
  'pciemdrv2app',
  'mdrv2.cpp',
  'pcie.cpp',
  cpp_args: cpp_args_pcie,
  dependencies: [
    boost_dep,
    sdbusplus_dep,
    phosphor_logging_dep,
    phosphor_dbus_interfaces_dep,
  ],
  implicit_include_directories: false,
  include_directories: root_inc,
  install: true,
)

subdir('pcie-ipmi-blobs')
