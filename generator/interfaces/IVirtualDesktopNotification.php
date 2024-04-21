<?php

// Import helper functions from the native PHP namespace:
namespace Kawapure\VirtualDesktops\Interfaces;

// Set the namespace context of the generated file:
SetNamespace("Kawapure", "VirtualDesktops");

DeclareInterface("IVirtualDesktopNotification",
    ForVersion("10240"),
    VirtualMethod("VirtualDesktopCreated",
        Argument(Type("IVirtualDesktop")->ptr(), "pDesktop"),
    ),
);

ProxyInterface("IVirtualDesktopNotification",
    VirtualMethod("VirtualDesktopCreated", InheritVersion("22000"))
);

GenerateProxyClasses("IVirtualDesktopNotification");