systemd_dep = dependency('systemd')
systemd_system_unitdir = systemd_dep.get_variable(
  'systemd_system_unit_dir',
  pkgconfig_define: ['rootprefix', get_option('prefix')]
  )

install_data('pcie-mdrv2.service', install_dir: systemd_system_unitdir)
