<?php
namespace Kawapure\VirtualDesktops\Generator;

/**
 * Manages global state for the build environment.
 *
 * @static
 */
final class Environment
{
    /**
     * Initialises the build environment.
     */
    public static function init(): void
    {
        // Run standard initialisation actions.
        InitActions::run();
    }
}