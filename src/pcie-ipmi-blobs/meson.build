ipmi_blob_dep = dependency('phosphor-ipmi-blobs')
libipmid_dep = dependency('libipmid').partial_dependency(includes: true)

pciestore_common_deps = [ipmi_blob_dep, libipmid_dep, sdbusplus_dep]

shared_module(
  'pciestore',
  'main.cpp',
  'handler.cpp',
  dependencies: [
    pciestore_common_deps,
    phosphor_logging_dep,
    ],
  include_directories: root_inc,
  install: true,
  install_dir: get_option('libdir') / 'blob-ipmid'
  )
