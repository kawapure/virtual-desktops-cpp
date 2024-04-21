# Virtual Desktops C++ :: Generator

This folder contains the PHP source code responsible for generating the C++ library.

## Directory structure

- `interfaces/` - **All virtual desktop interface definitions.**
- `backend/` - Things used by the PHP project backend, such as PHP classes.
- `vendor/` - Third-party PHP utilities used in the project.
- `templates/` - Twig templates used for formatting C++ source code files.

## Build requirements

PHP 8.0 and the Composer package manager are requirements for this build environment.

To set up the environment for building, first install dependencies via Composer: `composer install`.

To begin a build, run `php build_cpp.php`.

## Rationale

Public APIs for interacting with the virtual desktop system in Windows 10+ are very limited. For example, you can't even listen for when the virtual desktop is switched by the user.

Although the internal interfaces never changed during Windows 10's lifetime (Iron doesn't count!), they have changed substantially during 11's still-ongoing development.

This is a bad situation for any project like this. You can either only target one particular operating system, or spend hours of your life trying to figure out how to possibly support multiple different versions of the same interfaces at the same time. Neither COM nor C++ provide the facilties for this, so some mess of dynamic dispatch is the only option you have if you want to meaningfully support multiple Windows versions with one binary.

The approach used for this project makes interfacing comfortable for any developer using the library, at the expense of being a complete shitshow behind the scenes. I would simply rather not maintain a mess of subtly-different C++ interfaces and their respective multiple behaviour proxies all on my own. That's why I opted for code generation instead.