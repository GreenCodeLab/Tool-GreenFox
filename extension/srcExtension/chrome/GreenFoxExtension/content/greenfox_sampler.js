/**
 * Gets CPU thicks measure using XPCOM component
 */
var sampler = {

	addMethod: null, //DEBUG
	startMethod: null,

	init: function() {
		try {
			
			/* import js-ctypes */
			Components.utils.import("resource://gre/modules/ctypes.jsm");
			
			AddonManager.getAddonByID("greenfox@octo.com", function(addon) {
				var libcPath = addon.getResourceURI("components/library.dll");
				
				if (libcPath instanceof Components.interfaces.nsIFileURL) {
				
					var libc = ctypes.open(libcPath.file.path);

					/* declare available functions */
					
					// addMethod : Debug test
					addMethod = libc.declare("add", /* function name */
							   ctypes.default_abi, /* call ABI */
							   ctypes.int32_t, /* return type */
							   ctypes.int32_t, /* argument type */
							   ctypes.int32_t /* argument type */
					);
					  
					// startMethod
					// startMethod = libc.declare("start", /* function name */
							   // ctypes.default_abi, /* call ABI */
							   // ctypes.int32_t, /* return type */
					// );

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

		// TODO : call start

	},
	endMeasure: function() {
		//DEBUG
		return 666666666;
	},
}

/**
 * Gets CPU thicks measure. This objet is just a mock.
 */
var mockSampler = {
	init: function() {
		return true;
	},
	destroy: function() {},
	startMeasure: function() {
	},
	endMeasure: function() {
		return Math.floor(Math.random() * 100000000);
	},
}


