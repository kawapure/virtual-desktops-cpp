<?php
namespace Kawapure\VirtualDesktops\Generator;

/**
 * Utilities for interacting with the console.
 *
 * Since the console is a shared resource for the whole application, I
 * found no problem making this a static class.
 *
 * @static
 */
final class Console
{
    /**
     * Stores the current ANSI escape code used for formatting the text.
     *
     * This encodes the current formatting settings and colour, and must
     * be reencoded if any of them are set.
     */
    private static string $currentFormattingCode = "";

    /**
     * Stores currently-used formatting options.
     */
    private static array $currentFormatting = [];

    /**
     * Stores the currently-used colour.
     */
    private static string $currentColor = "";

    /**
     * Maps human-readable names to ANSI formatting code IDs.
     */
    private const FORMAT_CODES = [
        "bold" => 1,
        "italic" => 3,
        "underline" => 4,
        "strikethrough" => 9
    ];

    /**
     * Maps human-readable names to ANSI colour code offsets.
     */
    private const COLOR_CODES = [
        "black" => 0,
        "red" => 1,
        "green" => 2,
        "yellow" => 3,
        "blue" => 4,
        "magenta" => 5,
        "pink" => 5,
        "cyan" => 6,
        "lightblue" => 6,
        "white" => 7
    ];

    /**
     * The offset added to the colour code for getting ANSI foreground colour codes.
     */
    private const FG_COLOR_OFFSET = 30;

    /**
     * The offset added to the colour code for getting ANSI background colour codes.
     */
    private const BG_COLOR_OFFSET = 40;

    /**
     * Logs variables to the console.
     */
    public static function log(mixed ...$vars): void
    {
        foreach ($vars as $var)
        {
            echo $var;
            echo "\n";
        }
    }

    /**
     * Prints a formatted message to the console.
     */
    public static function printf(string $template, mixed ...$args): void
    {
        $text = sprintf($template, ...$args);

        echo $text;
        echo "\n";
    }

    /**
     * Logs variables to the console, all in a given colour.
     */
    public static function logInColor(string $colorCode, mixed ...$vars): void
    {
        self::setColor($colorCode);
        self::log($vars);
        self::setColor("default");
    }

    /**
     * Logs an error message to the console.
     *
     * This is basically just the same as logging in red, but red is the
     * colour given to error messages.
     */
    public static function error(mixed ...$vars): void
    {
        self::logInColor("red", ...$vars);
    }

    /**
     * Sets the colour of foreground text in the console.
     */
    private static function setColor(string $colorName): void
    {
        if ($colorName == "default")
        {
            self::$currentColor = "";
        }
        else
        {
            if (self::lookupColorName($colorName, $result))
            {
                self::$currentColor = $result;
            }
            else
            {
                // I don't feel this error condition is worthy of killing the program
                // over, so I'll just have it report a small runtime error instead.
                self::error("Attempted to set nonexistent color name: $colorName");
                return;
            }
        }

        self::refreshCurrentFormattingCode();
    }

    /**
     * Looks up a given colour name.
     *
     * @return bool True if the colour name is valid, otherwise false.
     */
    private static function lookupColorName(string $colorName, string &$out): bool
    {
        if (isset(self::COLOR_CODES[$colorName]))
        {
            $out = self::COLOR_CODES[$colorName];
            return true;
        }

        return false;
    }

    /**
     * Clears active formatting settings.
     *
     * This must be ran every time after formatting options are updated, in case
     * anything is cleared at all.
     */
    private static function clearFormatting(): void
    {
        echo "\e[0m";
    }

    /**
     * Refreshes the currently used formatting code.
     *
     * This must be done every time an action that affects the formatting code is taken.
     */
    private static function refreshCurrentFormattingCode(): void
    {
        self::clearFormatting();
    }
}