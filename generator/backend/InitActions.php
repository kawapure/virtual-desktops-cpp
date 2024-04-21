<?php
namespace Kawapure\VirtualDesktops\Generator;

/**
 * Implements actions to run at environment startup.
 *
 * @static
 */
final class InitActions
{
    /**
     * Runs all standard initialisation actions.
     */
    public static function run(): void
    {
        // Initialise the interface helpers, which are extensively
        // used later on.
        require "backend/include/init_interface_helpers.php";

        // Register all common types
        self::registerCommonTypes();
    }

    private static function registerCommonTypes(): void
    {
        
    }
}