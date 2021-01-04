[![Build Status](https://travis-ci.com/czm35388/adtf_bufferconfig_to_mapfile_converter.svg?branch=master)](https://travis-ci.com/czm35388/adtf_bufferconfig_to_mapfile_converter) 
[![codecov](https://codecov.io/gh/czm35388/adtf_bufferconfig_to_mapfile_converter/branch/master/graph/badge.svg)](https://codecov.io/gh/czm35388/adtf_bufferconfig_to_mapfile_converter)

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

## Converting syntax

| __old buffer xml node__ | __new map xml node__ | __comment__ |
| - | - | - |  
| ```<output>```  | ```<inputs>```  | input pins |
| ```<input>```   | ```<outputs>``` | output pins |
| ```<buffer>```  | ```<input>``` or ```<output>``` | pin description |
| ```<struct>```  | ```<struct>``` | pin description |
| ```<element>``` | ```<assignment>``` | signal element |


### Example for old buffer-configuration-file (.xml)

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
        </buffer>
    </input>
    <output>
        <buffer name="CalibData_1" pack="1" daq_event="100ms">
            <struct pack="1">
                <element type="tUInt8"  name="nTestKennfeld" signal="TestByte_983"/>
                <element type="tUInt16"  name="nKL7" signal="TestWord_001" />
            </struct>
    </output>
</settings>
```

### Example for new Mapfile (.map)

```xml
<?xml version="1.0" encoding="iso-8859-1" standalone="no"?>
<mapping codec="XCP" version="2.00">
    <outputs>
        <output name="MeasData" polling_interval="100000">
            <assignment>
                <to>testudword1</to>
                <from>signals.testudword1</from>
                <type>tUInt32</type>
                <unit_conversion>false</unit_conversion>
            </assignment>
            <assignment>
                <to>period</to>
                <from>parameters.period</from>
                <type>tFloat32</type>
                <unit_conversion>false</unit_conversion>
            </assignment>
            <assignment>
                <to>period_d</to>
                <from>parameters.period_d</from>
                <type>tFloat64</type>
                <unit_conversion>false</unit_conversion>
            </assignment>
        </output>
    </outputs>
</mapping>
```