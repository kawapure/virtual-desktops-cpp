<?php
namespace Kawapure\VirtualDesktops\Generator\Type;

/**
 * Base class for all type information classes.
 */
abstract class BaseType
{
    /**
     * The name of the type.
     */
    protected string $typeName;

    /**
     * The name of the type in the C++ context.
     */
    protected string $cppTypeName;

    public function __construct(string $typeName, string $cppTypeName = "")
    {
        $this->typeName = $typeName;

        $this->cppTypeName = empty($cppTypeName)
            ? $typeName
            : $cppTypeName;
    }

    public function getTypeName(): string
    {
        return $this->typeName;
    }

    public function getCppTypeName(): string
    {
        return $this->cppTypeName;
    }
}