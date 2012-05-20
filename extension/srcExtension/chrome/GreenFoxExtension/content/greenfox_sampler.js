/**
 * Gets CPU thicks measure using DLL
 */
var sampler = {
	libc: null,
	startMethod: null,
	stopMethod: null,
	initialValue: 0,

	init: function() {
		try {
			
			/* import js-ctypes */
			Components.utils.import("resource://gre/modules/ctypes.jsm");
			
			AddonManager.getAddonByID("greenfox@octo.com", function(addon) {
				var libcPath = addon.getResourceURI("components/greenfox.so"); //LINUX version
				// var libcPath = addon.getResourceURI("components/greenfox.dll"); //WINDOWS version
				
				if (libcPath instanceof Components.interfaces.nsIFileURL) {
				
					libc = ctypes.open(libcPath.file.path);

					/* declare available functions */
					
					// startMethod
					startMethod = libc.declare("start", /* function name */
						ctypes.default_abi, 			/* call ABI */
						ctypes.int32_t 					/* return type */
					);
					
					// stopMethod
					stopMethod = libc.declare("stop", 	/* function name */
						ctypes.default_abi, 			/* call ABI */
						ctypes.int32_t, 				/* return type */
						ctypes.int32_t 					/* argument type */
					);
				}
			});

			return true;
		} catch( e ) {
			alert( e );
			return false;
		}		
	},
	destroy: function() {
		libc.close(); //Closes cleanly the library opened through ctypes.open
	},
	startMeasure: function() {
		initialValue = startMethod();
	},
	endMeasure: function() {
		var finalValue = stopMethod(initialValue);
		return finalValue;
	},
}
