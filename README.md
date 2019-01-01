# X11-CW

## Introduction

A C/C++ API for use with NLP based projects. This accepts a string or sentence and then works with it to generate a
word count table for people to work with. This map will allow people to generate the probability maps for all words at 
required depths.


## Prerequisites

GCC is the only requirement to work with this API.

## Using it

To make use of it, one must include the C header in such a manner:
```C
	#include"adiction/core/core.h"
```
That would automatically take care of most of the things automatically.
To generate a map of words there are only two ways.
1. As a text.
	```C
		adict("some text required to be mapped","t");
	```
2. As a file.
	```C
		adict("filepath","f");
	```

To reset, simply delete the folder "words" that is autogenerated by the API.


**Note**
Project is under development. It is not in working order. It is under evaluation and testing.

