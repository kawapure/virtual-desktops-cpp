# Virtual Desktops API

This library allows you to control Windows's virtual desktops API, introduced in Windows 10, in your own C++ applications.

## OS support

- [ ] Windows 10 1507-22H2 (10240-19045).
- [ ] Windows 11 21H2 (22000)
- [ ] Windows 11 22H2 (22621)

## Contributing

This project is a little too complicated for me to take on in C++ alone. In order to make it a little easier, I wrote some scripts in PHP to generate C++ source code files. I'm sorry for being evil.

The source code generator can be found in `generator/`. To rebuild it, run `php build_cpp.php` in that folder. For more information, please see [generator/README.md](generator/README.md).