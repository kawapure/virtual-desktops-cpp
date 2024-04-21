<?php
namespace Kawapure\VirtualDesktops\Generator\Type\Common;

/**
 * Represents a name of something.
 */
class Name implements \Stringable
{
    private string $name;
    private CNamespace $namespace;
}