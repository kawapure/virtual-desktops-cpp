<?php
namespace Kawapure\VirtualDesktops\Generator;

/**
 * Stores information about all registered types.
 */
class TypeRegistry
{
    private static array $reg = [];

    /**
     * Registers a class to a name.
     */
    public static function register(string $name, string $objName): void
    {
        self::$reg[$name] = $objName;
    }

    /**
     *
     */
    public static function getTypeClass(string $name): ?string
    {
        if (isset(self::$reg[$name]))
        {
            return self::$reg[$name];
        }

        return null;
    }
}