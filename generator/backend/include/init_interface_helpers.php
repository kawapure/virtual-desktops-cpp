<?php

/*
 * -- カワプレの Virtual Desktops API --
 *
 * Initialises the helper functions used by the interface files.
 *
 * This must be included after the autoloader, or an error will
 * occur.
 */

// This is the namespace used for this environment.
namespace Kawapure\VirtualDesktops\Interfaces;

/**
 * Sets the namespace of the current file.
 */
function SetNamespace(...$parts)
{

}

/**
 * Declares the implementation version of the interface.
 *
 * This can technically be any string, but I tend to keep it as the
 * OS build number for consistency and convenience.
 */
function ForVersion()
{

}

/**
 * Inherits the properties from a specific version for proxy definitions.
 *
 * This may only be used in the context of a proxy implementation, and
 * will fail for any other type.
 */
function InheritVersion()
{

}

/**
 * Sets a name.
 *
 * Note that names can often be substituted with a string literal, so
 * the former is often preferred.
 */
function Name(...$info)
{

}

/**
 * Declares a pure interface, which by C++ standards is a class or
 * structure which consists only of virtual methods.
 */
function DeclareInterface(...$info)
{

}

/**
 * Declares a proxy interface.
 *
 * Proxy interfaces implement a version-independent frontend for the
 * version-dependent controller (sender) classes.
 *
 * Basically, they only exist to make handling types in C++ a little bit
 * nicer.
 */
function ProxyInterface(...$info)
{

}

/**
 * Generate proxy classes for a proxy interface.
 */
function GenerateProxyClasses(...$info)
{

}

/**
 * Declares the base type of a class or interface.
 *
 * Since C++ classes and interfaces can inherit from multiple other ones,
 * this may be specified multiple times.
 */
function Base(...$info)
{

}

/**
 * Defines an internal overload identifier, which is only used by the
 * generator script.
 *
 * This is used in the case of name conflicts in order to disambiguate
 * names easily, without needing to specify function parameters or
 * other verbose information.
 */
function OverloadInternalName(string $name)
{

}

/**
 * Declares a virtual method inside of a class or interface.
 */
function VirtualMethod(...$info)
{

}

/**
 * Represents a function argument.
 */
function Argument(...$info)
{

}

/**
 * Represents a type name, such as int or void.
 *
 * This is checked, so the type names must correspond to an existing
 * type at compile time or a compile error will occur. You can bypass
 * this using UncheckedType.
 */
function Type(...$info): object
{
    return (object)[];
}

/**
 * Represents any arbitrary type name.
 *
 * Note that an unchecked type explicitly does not have to be defined,
 * so misuse of it can result in invalid output.
 */
function UncheckedType(...$info): object
{
    return (object)[];
}