<?php

/*
 * -- カワプレの Virtual Desktops API --
 *
 * This file implements and registers the autoload procedure, which is
 * called by PHP automatically when an unrecognized type name is attempted
 * to be used.
 *
 * This basically just avoids having to import every file by hand.
 */

namespace Kawapure\VirtualDesktops\Generator;

/**
 * Manages type autoloading.
 */
class Autoloader
{
    /**
     * Registered autoloader function.
     */
    public static function autoload(string $classPath): void
    {
        $relativeFilePath = str_replace(
            "\\",
            "/",
            self::resolveClassNameFromPath($classPath)
        );

        if (file_exists("backend/$relativeFilePath.php"))
        {
            require "backend/$relativeFilePath.php";
        }
    }

    /**
     * Resolves the class name from a path.
     *
     * This is used because the layout of files on the disk don't exactly correspond
     * to a class's namespace. They must be corrected to remove a portion of the
     * namespace.
     */
    private static function resolveClassNameFromPath(string $path): string
    {
        return str_replace("Kawapure\\VirtualDesktop\\Generator\\", "", $path);
    }
}

spl_autoload_register(Autoloader::class . "::autoload");