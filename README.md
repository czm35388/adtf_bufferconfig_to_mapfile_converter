[![Build Status](https://travis-ci.com/czm35388/adtf_bufferconfig_to_mapfile_converter.svg?branch=master)](https://travis-ci.com/czm35388/adtf_bufferconfig_to_mapfile_converter) 

# Converter for ADTF2 BufferConfigurationfile (ADTF2) to Mapfile (ADTF3)

This repository includes a converter for ADTF2 BufferConfigurationfiles to ADTF3 Mapfiles.
They are used for initializing the De-/Encoderfilter for the Device- and Calibrationtoolbox.

You can use this tool within your toolchain to converter the old ADTF2 xml files to the new ADTF3 map file standard.

The tool will be deliverd as executable for 
* Windows
* Unix 
machines.

Simple in usage, fast converting and a possible debugging of the converter are the positiv apsects of this tool.
The implementation is based on the "pugixml" parser.

Example Bufferconfiguration file:

```xml
<?xml version="1.0" encoding="utf-8" standalone="no"?>
<settings>
    <input>
        <buffer name="MeasData_1" pack="1" daq_event="100ms" daq_prescaler="10">
            <struct pack="1">
                <element type="tUInt8"  name="nTestKennfeld" signal="TestByte_983"/>
                <element type="tUInt16"  name="nKL7" signal="TestWord_001" />
            </struct>
            <struct pack="1" array="idx=15:16" array_format="%03d">
                <element type="tFloat32"  name="fKL" signal="TestByte_$idx$" />
            </struct>
            <struct pack="1">
                <element type="tFloat32"  name="fNoise_ampl" signal="noise_ampl" />
                <element type="tUInt32"  name="nTest" signal="TestDWord_996" />
                <element type="tUInt8"  name="nKL3" signal="TestByte_000" />
            </struct>
        </buffer>
    </input>
    <output>
        <buffer name="CalibData_1" pack="1" daq_event="100ms">
            <struct pack="1">
                <element type="tUInt8"  name="nTestKennfeld" signal="TestByte_983"/>
                <element type="tUInt16"  name="nKL7" signal="TestWord_001" />
            </struct>
            <struct pack="1" array="idx=15:16" array_format="%03d">
                <element type="tFloat32"  name="fKL" signal="TestByte_$idx$" />
            </struct>
            <struct pack="1">
                <element type="tFloat32"  name="fNoise_ampl" signal="noise_ampl" />
                <element type="tUInt32"  name="nKL3" signal="TestDWord_996" />
            </struct>
        </buffer>
    </output>
    <output>
        <buffer name="CalibData_2" pack="1">
            <struct pack="1">
                <element type="tUInt8"  name="nBypassState" signal="TestByte_993"/>
            </struct>
        </buffer>
    </output>
</settings>
```
