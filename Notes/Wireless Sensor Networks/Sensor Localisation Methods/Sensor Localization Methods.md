# Localization methods in Wireless Sensor Networks

To get a bit of a context... a `wireless sensor network` is a network of *`sensors`* where the means by which the sensor nodes in the network communicate and send or receive data is wireless or through radio waves. In other words, they are not physically by a cable.

- A `sensor node` in this context, is simply referred to as *`a node`*.
- A `sensor` is a self-contained autonomous embedded system, comprised of: 1-some sort of an *`actual sensor`* (e.g. temperature), 2-*`microcontroller board`* the sensor is connected to, 3-a *`battery management system`*, 4-an actual battery and 5-an *`antenna`* (either on-board/internal or an external)

The nodes could be deployed either:
- locally
- geographically

When they are `deployed locally`, it's usually a case of a large in-door area that needs to be monitored (e.g. a warehouse) or a large structural system that needs monitoring (e.g. a bridge)

When they are `deployed geographically`, it's usually in an inaccessible and/or remote area (such as a desert, a disaster relief area, at sea, etc.) where certain (usually) environmental physical quantities need to be monitored (e.g. temperature, wind speed, atmospheric pressure, etc.).

There are generally `two major problems` associated with WSNs or *Wireless Sensor Networks* (there are more, but these seem to be the more pronounced of the bunch):
- `autonomy`
    - referring to *energy autonomy* or simply put *how efficient is the sensor node in managing its battery*)
- `localization`
    - giving the sensor's output a geo-spacial or positional context - especially when they are deployed globally (what good is the output the sensor is serving if we don't know where it's coming from? Sure, the sensor is bound to an ID and that's fixed or given, but the location is not, it can change due to external factors)

But there's also a more important reason why the exact or even relative position of a sensor is even more important and that's `optimization`! Knowing the position of each sensor, we could easily map the `topology of the network`. Knowing the topology, we could plan the network's redundancy (what to do in case one node - or an entire segment (!) - goes offline and disconnected and how it will affect the functionality and intended purpose of the WSN). Knowing the network's topology, we could determine the shortest path from each node to the central hub collecting and further processing the data coming from each of the sensors and so on. This comes especially into play when dealing with `data aggregation`.

Enough context. Let's deal with the different ways of localizing the nodes in a WSN!

`GPS` is certainly one way of dealing with localization. But it too has its inherent problems. For one, it only works indoors but this is not a problem if we restrict our discussion to localizing globally deployed sensors. Second, it's not strictly speaking, ver accurate. But more importantly, it requires additional HW in the sensor board. Additional HW means more power consumed - even more so when connecting to a satellite and transmitting the location (keep in mind this is an iterative process!). And that's one way to hugely impact the sensor's autonomy!

## Methods for sensor localization in WSNs

*... to be reviewed!*

![Sensor localization](/Assets/Sensor%20Localization%20Methods/Sensor%20Localization%20Methods.svg)

- `Target/Source Localization` is used both for indoors and outdoors applications (tracking vehicles, aircraft, sea animals, etc.)
- `Self-localization` techniques rely on determining a node's position relative to the other nodes
    - `Range-based` techniques rely on 'measuring' the proximity (distance and angle!) between a node of interest and a *`landmark node`* with a known position based on the following sub-techniques
        - `TOA` or *`Time Of Arrival`*
        - `TDOA` or *`Time Difference Of Arrival`*
        - `RSS/RSI` or *`Received Signal Strength or Received Signal Intensity`*
        - `AOA` or *`Angle Of Arrival`*
    - `Range-free` techniques rely solely solely on the content of the message each node is transmitting
        - `Pattern machine` or local-based techniques
        - `Hop counting` techniques

## Classification
- Indoor vs. Outdoor
- Absolute vs. Relative

## Absolute
... vs. an absolutely known landmark, with a fixed position

## Relative
... vs. other nodes that may or may not have a fixed position

- Lateration
    - Single (determining the distance from a single source)
    - Trilateration (... from three other nodes)
    - Multilateration (... from multiple nodes)
        - Atomic
        - Iterative
        - Collaborative
- Angulation
    - Single (determining the angle from a single source)
    - Triangulation (... from three other nodes)
    - Multiangulation (... from multiple nodes)
