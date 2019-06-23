/**
 * @license Copyright (c) 2003-2018, CKSource - Frederico Knabben. All rights reserved.
 * For licensing, see https://ckeditor.com/legal/ckeditor-oss-license
 */

CKEDITOR.editorConfig = function( config ) {
	// Define changes to default configuration here. For example:
	// config.language = 'fr';
	// config.uiColor = '#AADC6E';
    config.filebrowserUploadMethod = "form";
    config.filebrowserImageUploadUrl = "/admin/system/editorUpload";
    // config.extraPlugins = 'button,toolbar,notification,clipboard,lineutils,dialogui,dialog,widgetselection,widget,image2,uicolor';
    config.removeDialogTabs = "image:advanced;link:advanced";
    config.filebrowserImageBrowseUrl = '/admin/imageManager';

};
