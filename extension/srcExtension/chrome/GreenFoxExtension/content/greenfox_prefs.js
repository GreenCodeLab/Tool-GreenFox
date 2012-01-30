/**
 * GreenFox preferences dialog box management.
 */
var greenfoxPrefsMgr = {
	getPrefs: function() {
		return Components.classes["@mozilla.org/preferences-service;1"]
				.getService(Components.interfaces.nsIPrefService).getBranch("extensions.greenfox.");
	},
	getDefaultPrefs: function() {
		return Components.classes["@mozilla.org/preferences-service;1"]
				.getService(Components.interfaces.nsIPrefService).getDefaultBranch("extensions.greenfox.");
	},
	/**
	 * Init dialog box with GreenFox preferences.
	 */
	dialogInit: function() {
		try {
			var prefs = this.getPrefs();
			document.getElementById("greenfox-endpoint").value = prefs.getCharPref('endpoint');
			document.getElementById("greenfox-challengerID").value = prefs.getCharPref('challengerID');
			document.getElementById("greenfox-collection-enabled").checked = prefs.getBoolPref('collection.enabled');
		} catch (e) {
			alert("Failed to load settings.\n" + e);
		}
	},
	/**
	 * Check submitted values & set preferences.
	 * @return true if values are OK
	 */
	dialogSave: function() {
		try {
			var oPrefs = this.getPrefs();
			
			var challengerID = this.readValueFromDialog("greenfox-challengerID");
			var endpointVal = this.readValueFromDialog("greenfox-endpoint");
			var collectionEnabled = this.readCheckboxFromDialog("greenfox-collection-enabled");

			if( this.dialogValidate( challengerID, endpointVal ) ) {
				oPrefs.setCharPref('endpoint', endpointVal)
				oPrefs.setCharPref('challengerID', challengerID)
				oPrefs.setBoolPref('collection.enabled', collectionEnabled)
				return true;
			} else {
				return false;
			}
		} catch (e) {
			alert("Failed to load settings.\n" + e);
			return false;
		}
	},
	readValueFromDialog: function(domId) {
		// Get submitted value:
		var value = document.getElementById(domId).value;
		// Trim spaces:
		value = value.replace(/^\s+/g,'').replace(/\s+$/g,'');
		return value;
	},
	readCheckboxFromDialog: function(domId) {
		var value = document.getElementById(domId).checked;
		return value;
	},
	/**
	 * Validate submitted preferences.
	 * @param challengerID challenger ID to validate
	 * @param endpointVal endpoint URL to validate
	 * 
	 * @return true if all is OK
	 */
	dialogValidate: function(challengerID, endpointVal) {
		var validate = function(value,regexp,what) {
			var lengthValue = value.length;
			if(lengthValue > 0) {
				var r = new RegExp();
				r.compile(regexp);
				if (!r.test( value ))
				{
					alert("Invalid " + what);
					return false;
				}
			} else {
				// lengthValue==0
				return false;
			}
			return true;
		};
		// TODO implement email validation
		return validate(endpointVal,"^https?://([A-Za-z0-9\-\./]|:)+$","URL") /*&& validate(challengerID,"^.*@.*$","email")*/
	},
	/**
	 * Revert to factory settings.
	 */
	dialogReset: function() {
		var defaults = this.getDefaultPrefs()
		document.getElementById("greenfox-endpoint").value = defaults.getCharPref("endpoint");
		document.getElementById("greenfox-challengerID").value = defaults.getCharPref("challengerID");
		document.getElementById("greenfox-collection-enabled").checked = defaults.getBoolPref("collection.enabled");
	},
}

