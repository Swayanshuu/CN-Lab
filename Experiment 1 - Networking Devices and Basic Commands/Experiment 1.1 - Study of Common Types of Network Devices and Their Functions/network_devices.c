#include <stdio.h>

// Simple program to study common network devices and their operating layers
struct Device {
    char name[20];
    char layer[25];
    char function[80];
};

int main() {
    struct Device d[] = {
        {"NIC", "Physical & Data Link", "Provides physical connection and MAC address"},
        {"Hub", "Physical (Layer 1)", "Broadcasts data to all ports (dummy device)"},
        {"Switch", "Data Link (Layer 2)", "Forwards frame to destination port using MAC"},
        {"Router", "Network (Layer 3)", "Routes packets between networks using IP"},
        {"Access Point", "Data Link (Layer 2)", "Extends wired network wirelessly (Wi-Fi)"},
        {"Modem", "Physical (Layer 1)", "Converts between analog and digital signals"},
        {"Repeater", "Physical (Layer 1)", "Amplifies and regenerates weak signals"},
        {"Bridge", "Data Link (Layer 2)", "Connects two LAN segments to reduce collisions"},
        {"Gateway", "All Layers (4 to 7)", "Translates protocols between dissimilar networks"}
    };

    int n = sizeof(d) / sizeof(d[0]);

    printf("Common Network Devices and Their Functions:\n\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %-15s [%s]\n   Role: %s\n\n", i + 1, d[i].name, d[i].layer, d[i].function);
    }

    return 0;
}

/*
Example Output:

Common Network Devices and Their Functions:

1. NIC             [Physical & Data Link]
   Role: Connects device to medium and provides physical MAC address

2. Hub             [Physical (Layer 1)]
   Role: Broadcasts data to all ports (dummy device)

3. Switch          [Data Link (Layer 2)]
   Role: Forwards frame to destination port using MAC

4. Router          [Network (Layer 3)]
   Role: Routes packets between networks using IP

5. Access Point    [Data Link (Layer 2)]
   Role: Extends wired network wirelessly (Wi-Fi)

6. Modem           [Physical (Layer 1)]
   Role: Converts between analog and digital signals

7. Repeater        [Physical (Layer 1)]
   Role: Amplifies and regenerates weak signals

8. Bridge          [Data Link (Layer 2)]
   Role: Connects two LAN segments to reduce collisions

9. Gateway         [All Layers (4 to 7)]
   Role: Translates protocols between dissimilar networks
*/
