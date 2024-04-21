<?php
namespace Kawapure\VirtualDesktops\Generator\Type\Common;

/**
 * Defines a namespace path.
 *
 * C prefix used to avoid naming conflict with PHP keyword "namespace".
 */
class CNamespace implements \Stringable
{
    /**
     * The name of this namespace.
     */
    private string $name;

    /**
     * The parent namespace (if it exists).
     */
    private ?CNamespace $parent = null;

    /**
     * Get the parent of this namespace, if it exists.
     */
    public function getParent(): ?CNamespace
    {
        return $this->parent;
    }

    /**
     * Get the name of this namespace.
     */
    public function getName(): string
    {
        return $this->name;
    }

    /**
     * Get the path of this namespace.
     */
    public function getPath(): array
    {
        $names = [];

        $cur = $this;

        do
        {
            $names[] = $cur->getName();
        }
        while ($cur = $cur->parent);

        return array_reverse($names);
    }

    /**
     * Get the path of this namespace as a string.
     */
    public function getPathAsString(): string
    {
        return implode("::", $this->getPath());
    }

    //
    // interface Stringable
    //

    public function __toString(): string
    {
        return $this->getPathAsString();
    }
}