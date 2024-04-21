<?php
/*
 * Virtual Desktops C++ build script.
 *
 * This is the insertion point for the build environment.
 */

namespace Kawapure\VirtualDesktops\Generator;

require "vendor/autoload.php";
require "backend/include/autoloader.php";

Console::log("Beginning build...");

// Initialise the environment
Environment::init();