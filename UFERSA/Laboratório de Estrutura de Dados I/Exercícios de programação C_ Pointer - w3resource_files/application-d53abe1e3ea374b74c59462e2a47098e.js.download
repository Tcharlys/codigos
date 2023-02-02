(function($, undefined) {

/**
 * Unobtrusive scripting adapter for jQuery
 * https://github.com/rails/jquery-ujs
 *
 * Requires jQuery 1.8.0 or later.
 *
 * Released under the MIT license
 *
 */

  // Cut down on the number of issues from people inadvertently including jquery_ujs twice
  // by detecting and raising an error when it happens.
  'use strict';

  if ( $.rails !== undefined ) {
    $.error('jquery-ujs has already been loaded!');
  }

  // Shorthand to make it a little easier to call public rails functions from within rails.js
  var rails;
  var $document = $(document);

  $.rails = rails = {
    // Link elements bound by jquery-ujs
    linkClickSelector: 'a[data-confirm], a[data-method], a[data-remote]:not([disabled]), a[data-disable-with], a[data-disable]',

    // Button elements bound by jquery-ujs
    buttonClickSelector: 'button[data-remote]:not([form]):not(form button), button[data-confirm]:not([form]):not(form button)',

    // Select elements bound by jquery-ujs
    inputChangeSelector: 'select[data-remote], input[data-remote], textarea[data-remote]',

    // Form elements bound by jquery-ujs
    formSubmitSelector: 'form',

    // Form input elements bound by jquery-ujs
    formInputClickSelector: 'form input[type=submit], form input[type=image], form button[type=submit], form button:not([type]), input[type=submit][form], input[type=image][form], button[type=submit][form], button[form]:not([type])',

    // Form input elements disabled during form submission
    disableSelector: 'input[data-disable-with]:enabled, button[data-disable-with]:enabled, textarea[data-disable-with]:enabled, input[data-disable]:enabled, button[data-disable]:enabled, textarea[data-disable]:enabled',

    // Form input elements re-enabled after form submission
    enableSelector: 'input[data-disable-with]:disabled, button[data-disable-with]:disabled, textarea[data-disable-with]:disabled, input[data-disable]:disabled, button[data-disable]:disabled, textarea[data-disable]:disabled',

    // Form required input elements
    requiredInputSelector: 'input[name][required]:not([disabled]), textarea[name][required]:not([disabled])',

    // Form file input elements
    fileInputSelector: 'input[name][type=file]:not([disabled])',

    // Link onClick disable selector with possible reenable after remote submission
    linkDisableSelector: 'a[data-disable-with], a[data-disable]',

    // Button onClick disable selector with possible reenable after remote submission
    buttonDisableSelector: 'button[data-remote][data-disable-with], button[data-remote][data-disable]',

    // Up-to-date Cross-Site Request Forgery token
    csrfToken: function() {
     return $('meta[name=csrf-token]').attr('content');
    },

    // URL param that must contain the CSRF token
    csrfParam: function() {
     return $('meta[name=csrf-param]').attr('content');
    },

    // Make sure that every Ajax request sends the CSRF token
    CSRFProtection: function(xhr) {
      var token = rails.csrfToken();
      if (token) xhr.setRequestHeader('X-CSRF-Token', token);
    },

    // Make sure that all forms have actual up-to-date tokens (cached forms contain old ones)
    refreshCSRFTokens: function(){
      $('form input[name="' + rails.csrfParam() + '"]').val(rails.csrfToken());
    },

    // Triggers an event on an element and returns false if the event result is false
    fire: function(obj, name, data) {
      var event = $.Event(name);
      obj.trigger(event, data);
      return event.result !== false;
    },

    // Default confirm dialog, may be overridden with custom confirm dialog in $.rails.confirm
    confirm: function(message) {
      return confirm(message);
    },

    // Default ajax function, may be overridden with custom function in $.rails.ajax
    ajax: function(options) {
      return $.ajax(options);
    },

    // Default way to get an element's href. May be overridden at $.rails.href.
    href: function(element) {
      return element[0].href;
    },

    // Checks "data-remote" if true to handle the request through a XHR request.
    isRemote: function(element) {
      return element.data('remote') !== undefined && element.data('remote') !== false;
    },

    // Submits "remote" forms and links with ajax
    handleRemote: function(element) {
      var method, url, data, withCredentials, dataType, options;

      if (rails.fire(element, 'ajax:before')) {
        withCredentials = element.data('with-credentials') || null;
        dataType = element.data('type') || ($.ajaxSettings && $.ajaxSettings.dataType);

        if (element.is('form')) {
          method = element.data('ujs:submit-button-formmethod') || element.attr('method');
          url = element.data('ujs:submit-button-formaction') || element.attr('action');
          data = $(element[0]).serializeArray();
          // memoized value from clicked submit button
          var button = element.data('ujs:submit-button');
          if (button) {
            data.push(button);
            element.data('ujs:submit-button', null);
          }
          element.data('ujs:submit-button-formmethod', null);
          element.data('ujs:submit-button-formaction', null);
        } else if (element.is(rails.inputChangeSelector)) {
          method = element.data('method');
          url = element.data('url');
          data = element.serialize();
          if (element.data('params')) data = data + '&' + element.data('params');
        } else if (element.is(rails.buttonClickSelector)) {
          method = element.data('method') || 'get';
          url = element.data('url');
          data = element.serialize();
          if (element.data('params')) data = data + '&' + element.data('params');
        } else {
          method = element.data('method');
          url = rails.href(element);
          data = element.data('params') || null;
        }

        options = {
          type: method || 'GET', data: data, dataType: dataType,
          // stopping the "ajax:beforeSend" event will cancel the ajax request
          beforeSend: function(xhr, settings) {
            if (settings.dataType === undefined) {
              xhr.setRequestHeader('accept', '*/*;q=0.5, ' + settings.accepts.script);
            }
            if (rails.fire(element, 'ajax:beforeSend', [xhr, settings])) {
              element.trigger('ajax:send', xhr);
            } else {
              return false;
            }
          },
          success: function(data, status, xhr) {
            element.trigger('ajax:success', [data, status, xhr]);
          },
          complete: function(xhr, status) {
            element.trigger('ajax:complete', [xhr, status]);
          },
          error: function(xhr, status, error) {
            element.trigger('ajax:error', [xhr, status, error]);
          },
          crossDomain: rails.isCrossDomain(url)
        };

        // There is no withCredentials for IE6-8 when
        // "Enable native XMLHTTP support" is disabled
        if (withCredentials) {
          options.xhrFields = {
            withCredentials: withCredentials
          };
        }

        // Only pass url to `ajax` options if not blank
        if (url) { options.url = url; }

        return rails.ajax(options);
      } else {
        return false;
      }
    },

    // Determines if the request is a cross domain request.
    isCrossDomain: function(url) {
      var originAnchor = document.createElement('a');
      originAnchor.href = location.href;
      var urlAnchor = document.createElement('a');

      try {
        urlAnchor.href = url;
        // This is a workaround to a IE bug.
        urlAnchor.href = urlAnchor.href;

        // If URL protocol is false or is a string containing a single colon
        // *and* host are false, assume it is not a cross-domain request
        // (should only be the case for IE7 and IE compatibility mode).
        // Otherwise, evaluate protocol and host of the URL against the origin
        // protocol and host.
        return !(((!urlAnchor.protocol || urlAnchor.protocol === ':') && !urlAnchor.host) ||
          (originAnchor.protocol + '//' + originAnchor.host ===
            urlAnchor.protocol + '//' + urlAnchor.host));
      } catch (e) {
        // If there is an error parsing the URL, assume it is crossDomain.
        return true;
      }
    },

    // Handles "data-method" on links such as:
    // <a href="/users/5" data-method="delete" rel="nofollow" data-confirm="Are you sure?">Delete</a>
    handleMethod: function(link) {
      var href = rails.href(link),
        method = link.data('method'),
        target = link.attr('target'),
        csrfToken = rails.csrfToken(),
        csrfParam = rails.csrfParam(),
        form = $('<form method="post" action="' + href + '"></form>'),
        metadataInput = '<input name="_method" value="' + method + '" type="hidden" />';

      if (csrfParam !== undefined && csrfToken !== undefined && !rails.isCrossDomain(href)) {
        metadataInput += '<input name="' + csrfParam + '" value="' + csrfToken + '" type="hidden" />';
      }

      if (target) { form.attr('target', target); }

      form.hide().append(metadataInput).appendTo('body');
      form.submit();
    },

    // Helper function that returns form elements that match the specified CSS selector
    // If form is actually a "form" element this will return associated elements outside the from that have
    // the html form attribute set
    formElements: function(form, selector) {
      return form.is('form') ? $(form[0].elements).filter(selector) : form.find(selector);
    },

    /* Disables form elements:
      - Caches element value in 'ujs:enable-with' data store
      - Replaces element text with value of 'data-disable-with' attribute
      - Sets disabled property to true
    */
    disableFormElements: function(form) {
      rails.formElements(form, rails.disableSelector).each(function() {
        rails.disableFormElement($(this));
      });
    },

    disableFormElement: function(element) {
      var method, replacement;

      method = element.is('button') ? 'html' : 'val';
      replacement = element.data('disable-with');

      if (replacement !== undefined) {
        element.data('ujs:enable-with', element[method]());
        element[method](replacement);
      }

      element.prop('disabled', true);
      element.data('ujs:disabled', true);
    },

    /* Re-enables disabled form elements:
      - Replaces element text with cached value from 'ujs:enable-with' data store (created in `disableFormElements`)
      - Sets disabled property to false
    */
    enableFormElements: function(form) {
      rails.formElements(form, rails.enableSelector).each(function() {
        rails.enableFormElement($(this));
      });
    },

    enableFormElement: function(element) {
      var method = element.is('button') ? 'html' : 'val';
      if (element.data('ujs:enable-with') !== undefined) {
        element[method](element.data('ujs:enable-with'));
        element.removeData('ujs:enable-with'); // clean up cache
      }
      element.prop('disabled', false);
      element.removeData('ujs:disabled');
    },

   /* For 'data-confirm' attribute:
      - Fires `confirm` event
      - Shows the confirmation dialog
      - Fires the `confirm:complete` event

      Returns `true` if no function stops the chain and user chose yes; `false` otherwise.
      Attaching a handler to the element's `confirm` event that returns a `falsy` value cancels the confirmation dialog.
      Attaching a handler to the element's `confirm:complete` event that returns a `falsy` value makes this function
      return false. The `confirm:complete` event is fired whether or not the user answered true or false to the dialog.
   */
    allowAction: function(element) {
      var message = element.data('confirm'),
          answer = false, callback;
      if (!message) { return true; }

      if (rails.fire(element, 'confirm')) {
        try {
          answer = rails.confirm(message);
        } catch (e) {
          (console.error || console.log).call(console, e.stack || e);
        }
        callback = rails.fire(element, 'confirm:complete', [answer]);
      }
      return answer && callback;
    },

    // Helper function which checks for blank inputs in a form that match the specified CSS selector
    blankInputs: function(form, specifiedSelector, nonBlank) {
      var foundInputs = $(),
        input,
        valueToCheck,
        radiosForNameWithNoneSelected,
        radioName,
        selector = specifiedSelector || 'input,textarea',
        requiredInputs = form.find(selector),
        checkedRadioButtonNames = {};

      requiredInputs.each(function() {
        input = $(this);
        if (input.is('input[type=radio]')) {

          // Don't count unchecked required radio as blank if other radio with same name is checked,
          // regardless of whether same-name radio input has required attribute or not. The spec
          // states https://www.w3.org/TR/html5/forms.html#the-required-attribute
          radioName = input.attr('name');

          // Skip if we've already seen the radio with this name.
          if (!checkedRadioButtonNames[radioName]) {

            // If none checked
            if (form.find('input[type=radio]:checked[name="' + radioName + '"]').length === 0) {
              radiosForNameWithNoneSelected = form.find(
                'input[type=radio][name="' + radioName + '"]');
              foundInputs = foundInputs.add(radiosForNameWithNoneSelected);
            }

            // We only need to check each name once.
            checkedRadioButtonNames[radioName] = radioName;
          }
        } else {
          valueToCheck = input.is('input[type=checkbox],input[type=radio]') ? input.is(':checked') : !!input.val();
          if (valueToCheck === nonBlank) {
            foundInputs = foundInputs.add(input);
          }
        }
      });
      return foundInputs.length ? foundInputs : false;
    },

    // Helper function which checks for non-blank inputs in a form that match the specified CSS selector
    nonBlankInputs: function(form, specifiedSelector) {
      return rails.blankInputs(form, specifiedSelector, true); // true specifies nonBlank
    },

    // Helper function, needed to provide consistent behavior in IE
    stopEverything: function(e) {
      $(e.target).trigger('ujs:everythingStopped');
      e.stopImmediatePropagation();
      return false;
    },

    //  Replace element's html with the 'data-disable-with' after storing original html
    //  and prevent clicking on it
    disableElement: function(element) {
      var replacement = element.data('disable-with');

      if (replacement !== undefined) {
        element.data('ujs:enable-with', element.html()); // store enabled state
        element.html(replacement);
      }

      element.bind('click.railsDisable', function(e) { // prevent further clicking
        return rails.stopEverything(e);
      });
      element.data('ujs:disabled', true);
    },

    // Restore element to its original state which was disabled by 'disableElement' above
    enableElement: function(element) {
      if (element.data('ujs:enable-with') !== undefined) {
        element.html(element.data('ujs:enable-with')); // set to old enabled state
        element.removeData('ujs:enable-with'); // clean up cache
      }
      element.unbind('click.railsDisable'); // enable element
      element.removeData('ujs:disabled');
    }
  };

  if (rails.fire($document, 'rails:attachBindings')) {

    $.ajaxPrefilter(function(options, originalOptions, xhr){ if ( !options.crossDomain ) { rails.CSRFProtection(xhr); }});

    // This event works the same as the load event, except that it fires every
    // time the page is loaded.
    //
    // See https://github.com/rails/jquery-ujs/issues/357
    // See https://developer.mozilla.org/en-US/docs/Using_Firefox_1.5_caching
    $(window).on('pageshow.rails', function () {
      $($.rails.enableSelector).each(function () {
        var element = $(this);

        if (element.data('ujs:disabled')) {
          $.rails.enableFormElement(element);
        }
      });

      $($.rails.linkDisableSelector).each(function () {
        var element = $(this);

        if (element.data('ujs:disabled')) {
          $.rails.enableElement(element);
        }
      });
    });

    $document.on('ajax:complete', rails.linkDisableSelector, function() {
        rails.enableElement($(this));
    });

    $document.on('ajax:complete', rails.buttonDisableSelector, function() {
        rails.enableFormElement($(this));
    });

    $document.on('click.rails', rails.linkClickSelector, function(e) {
      var link = $(this), method = link.data('method'), data = link.data('params'), metaClick = e.metaKey || e.ctrlKey;
      if (!rails.allowAction(link)) return rails.stopEverything(e);

      if (!metaClick && link.is(rails.linkDisableSelector)) rails.disableElement(link);

      if (rails.isRemote(link)) {
        if (metaClick && (!method || method === 'GET') && !data) { return true; }

        var handleRemote = rails.handleRemote(link);
        // Response from rails.handleRemote() will either be false or a deferred object promise.
        if (handleRemote === false) {
          rails.enableElement(link);
        } else {
          handleRemote.fail( function() { rails.enableElement(link); } );
        }
        return false;

      } else if (method) {
        rails.handleMethod(link);
        return false;
      }
    });

    $document.on('click.rails', rails.buttonClickSelector, function(e) {
      var button = $(this);

      if (!rails.allowAction(button) || !rails.isRemote(button)) return rails.stopEverything(e);

      if (button.is(rails.buttonDisableSelector)) rails.disableFormElement(button);

      var handleRemote = rails.handleRemote(button);
      // Response from rails.handleRemote() will either be false or a deferred object promise.
      if (handleRemote === false) {
        rails.enableFormElement(button);
      } else {
        handleRemote.fail( function() { rails.enableFormElement(button); } );
      }
      return false;
    });

    $document.on('change.rails', rails.inputChangeSelector, function(e) {
      var link = $(this);
      if (!rails.allowAction(link) || !rails.isRemote(link)) return rails.stopEverything(e);

      rails.handleRemote(link);
      return false;
    });

    $document.on('submit.rails', rails.formSubmitSelector, function(e) {
      var form = $(this),
        remote = rails.isRemote(form),
        blankRequiredInputs,
        nonBlankFileInputs;

      if (!rails.allowAction(form)) return rails.stopEverything(e);

      // Skip other logic when required values are missing or file upload is present
      if (form.attr('novalidate') === undefined) {
        if (form.data('ujs:formnovalidate-button') === undefined) {
          blankRequiredInputs = rails.blankInputs(form, rails.requiredInputSelector, false);
          if (blankRequiredInputs && rails.fire(form, 'ajax:aborted:required', [blankRequiredInputs])) {
            return rails.stopEverything(e);
          }
        } else {
          // Clear the formnovalidate in case the next button click is not on a formnovalidate button
          // Not strictly necessary to do here, since it is also reset on each button click, but just to be certain
          form.data('ujs:formnovalidate-button', undefined);
        }
      }

      if (remote) {
        nonBlankFileInputs = rails.nonBlankInputs(form, rails.fileInputSelector);
        if (nonBlankFileInputs) {
          // Slight timeout so that the submit button gets properly serialized
          // (make it easy for event handler to serialize form without disabled values)
          setTimeout(function(){ rails.disableFormElements(form); }, 13);
          var aborted = rails.fire(form, 'ajax:aborted:file', [nonBlankFileInputs]);

          // Re-enable form elements if event bindings return false (canceling normal form submission)
          if (!aborted) { setTimeout(function(){ rails.enableFormElements(form); }, 13); }

          return aborted;
        }

        rails.handleRemote(form);
        return false;

      } else {
        // Slight timeout so that the submit button gets properly serialized
        setTimeout(function(){ rails.disableFormElements(form); }, 13);
      }
    });

    $document.on('click.rails', rails.formInputClickSelector, function(event) {
      var button = $(this);

      if (!rails.allowAction(button)) return rails.stopEverything(event);

      // Register the pressed submit button
      var name = button.attr('name'),
        data = name ? {name:name, value:button.val()} : null;

      var form = button.closest('form');
      if (form.length === 0) {
        form = $('#' + button.attr('form'));
      }
      form.data('ujs:submit-button', data);

      // Save attributes from button
      form.data('ujs:formnovalidate-button', button.attr('formnovalidate'));
      form.data('ujs:submit-button-formaction', button.attr('formaction'));
      form.data('ujs:submit-button-formmethod', button.attr('formmethod'));
    });

    $document.on('ajax:send.rails', rails.formSubmitSelector, function(event) {
      if (this === event.target) rails.disableFormElements($(this));
    });

    $document.on('ajax:complete.rails', rails.formSubmitSelector, function(event) {
      if (this === event.target) rails.enableFormElements($(this));
    });

    $(function(){
      rails.refreshCSRFTokens();
    });
  }

})( jQuery );
/* ========================================================================
 * Bootstrap: transition.js v3.1.1
 * http://getbootstrap.com/javascript/#transitions
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // CSS TRANSITION SUPPORT (Shoutout: http://www.modernizr.com/)
  // ============================================================

  function transitionEnd() {
    var el = document.createElement('bootstrap')

    var transEndEventNames = {
      'WebkitTransition' : 'webkitTransitionEnd',
      'MozTransition'    : 'transitionend',
      'OTransition'      : 'oTransitionEnd otransitionend',
      'transition'       : 'transitionend'
    }

    for (var name in transEndEventNames) {
      if (el.style[name] !== undefined) {
        return { end: transEndEventNames[name] }
      }
    }

    return false // explicit for ie8 (  ._.)
  }

  // http://blog.alexmaccaw.com/css-transitions
  $.fn.emulateTransitionEnd = function (duration) {
    var called = false, $el = this
    $(this).one($.support.transition.end, function () { called = true })
    var callback = function () { if (!called) $($el).trigger($.support.transition.end) }
    setTimeout(callback, duration)
    return this
  }

  $(function () {
    $.support.transition = transitionEnd()
  })

}(jQuery);
/* ========================================================================
 * Bootstrap: alert.js v3.1.1
 * http://getbootstrap.com/javascript/#alerts
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // ALERT CLASS DEFINITION
  // ======================

  var dismiss = '[data-dismiss="alert"]'
  var Alert   = function (el) {
    $(el).on('click', dismiss, this.close)
  }

  Alert.prototype.close = function (e) {
    var $this    = $(this)
    var selector = $this.attr('data-target')

    if (!selector) {
      selector = $this.attr('href')
      selector = selector && selector.replace(/.*(?=#[^\s]*$)/, '') // strip for ie7
    }

    var $parent = $(selector)

    if (e) e.preventDefault()

    if (!$parent.length) {
      $parent = $this.hasClass('alert') ? $this : $this.parent()
    }

    $parent.trigger(e = $.Event('close.bs.alert'))

    if (e.isDefaultPrevented()) return

    $parent.removeClass('in')

    function removeElement() {
      $parent.trigger('closed.bs.alert').remove()
    }

    $.support.transition && $parent.hasClass('fade') ?
      $parent
        .one($.support.transition.end, removeElement)
        .emulateTransitionEnd(150) :
      removeElement()
  }


  // ALERT PLUGIN DEFINITION
  // =======================

  var old = $.fn.alert

  $.fn.alert = function (option) {
    return this.each(function () {
      var $this = $(this)
      var data  = $this.data('bs.alert')

      if (!data) $this.data('bs.alert', (data = new Alert(this)))
      if (typeof option == 'string') data[option].call($this)
    })
  }

  $.fn.alert.Constructor = Alert


  // ALERT NO CONFLICT
  // =================

  $.fn.alert.noConflict = function () {
    $.fn.alert = old
    return this
  }


  // ALERT DATA-API
  // ==============

  $(document).on('click.bs.alert.data-api', dismiss, Alert.prototype.close)

}(jQuery);
/* ========================================================================
 * Bootstrap: modal.js v3.1.1
 * http://getbootstrap.com/javascript/#modals
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // MODAL CLASS DEFINITION
  // ======================

  var Modal = function (element, options) {
    this.options   = options
    this.$element  = $(element)
    this.$backdrop =
    this.isShown   = null

    if (this.options.remote) {
      this.$element
        .find('.modal-content')
        .load(this.options.remote, $.proxy(function () {
          this.$element.trigger('loaded.bs.modal')
        }, this))
    }
  }

  Modal.DEFAULTS = {
    backdrop: true,
    keyboard: true,
    show: true
  }

  Modal.prototype.toggle = function (_relatedTarget) {
    return this[!this.isShown ? 'show' : 'hide'](_relatedTarget)
  }

  Modal.prototype.show = function (_relatedTarget) {
    var that = this
    var e    = $.Event('show.bs.modal', { relatedTarget: _relatedTarget })

    this.$element.trigger(e)

    if (this.isShown || e.isDefaultPrevented()) return

    this.isShown = true

    this.escape()

    this.$element.on('click.dismiss.bs.modal', '[data-dismiss="modal"]', $.proxy(this.hide, this))

    this.backdrop(function () {
      var transition = $.support.transition && that.$element.hasClass('fade')

      if (!that.$element.parent().length) {
        that.$element.appendTo(document.body) // don't move modals dom position
      }

      that.$element
        .show()
        .scrollTop(0)

      if (transition) {
        that.$element[0].offsetWidth // force reflow
      }

      that.$element
        .addClass('in')
        .attr('aria-hidden', false)

      that.enforceFocus()

      var e = $.Event('shown.bs.modal', { relatedTarget: _relatedTarget })

      transition ?
        that.$element.find('.modal-dialog') // wait for modal to slide in
          .one($.support.transition.end, function () {
            that.$element.focus().trigger(e)
          })
          .emulateTransitionEnd(300) :
        that.$element.focus().trigger(e)
    })
  }

  Modal.prototype.hide = function (e) {
    if (e) e.preventDefault()

    e = $.Event('hide.bs.modal')

    this.$element.trigger(e)

    if (!this.isShown || e.isDefaultPrevented()) return

    this.isShown = false

    this.escape()

    $(document).off('focusin.bs.modal')

    this.$element
      .removeClass('in')
      .attr('aria-hidden', true)
      .off('click.dismiss.bs.modal')

    $.support.transition && this.$element.hasClass('fade') ?
      this.$element
        .one($.support.transition.end, $.proxy(this.hideModal, this))
        .emulateTransitionEnd(300) :
      this.hideModal()
  }

  Modal.prototype.enforceFocus = function () {
    $(document)
      .off('focusin.bs.modal') // guard against infinite focus loop
      .on('focusin.bs.modal', $.proxy(function (e) {
        if (this.$element[0] !== e.target && !this.$element.has(e.target).length) {
          this.$element.focus()
        }
      }, this))
  }

  Modal.prototype.escape = function () {
    if (this.isShown && this.options.keyboard) {
      this.$element.on('keyup.dismiss.bs.modal', $.proxy(function (e) {
        e.which == 27 && this.hide()
      }, this))
    } else if (!this.isShown) {
      this.$element.off('keyup.dismiss.bs.modal')
    }
  }

  Modal.prototype.hideModal = function () {
    var that = this
    this.$element.hide()
    this.backdrop(function () {
      that.removeBackdrop()
      that.$element.trigger('hidden.bs.modal')
    })
  }

  Modal.prototype.removeBackdrop = function () {
    this.$backdrop && this.$backdrop.remove()
    this.$backdrop = null
  }

  Modal.prototype.backdrop = function (callback) {
    var animate = this.$element.hasClass('fade') ? 'fade' : ''

    if (this.isShown && this.options.backdrop) {
      var doAnimate = $.support.transition && animate

      this.$backdrop = $('<div class="modal-backdrop ' + animate + '" />')
        .appendTo(document.body)

      this.$element.on('click.dismiss.bs.modal', $.proxy(function (e) {
        if (e.target !== e.currentTarget) return
        this.options.backdrop == 'static'
          ? this.$element[0].focus.call(this.$element[0])
          : this.hide.call(this)
      }, this))

      if (doAnimate) this.$backdrop[0].offsetWidth // force reflow

      this.$backdrop.addClass('in')

      if (!callback) return

      doAnimate ?
        this.$backdrop
          .one($.support.transition.end, callback)
          .emulateTransitionEnd(150) :
        callback()

    } else if (!this.isShown && this.$backdrop) {
      this.$backdrop.removeClass('in')

      $.support.transition && this.$element.hasClass('fade') ?
        this.$backdrop
          .one($.support.transition.end, callback)
          .emulateTransitionEnd(150) :
        callback()

    } else if (callback) {
      callback()
    }
  }


  // MODAL PLUGIN DEFINITION
  // =======================

  var old = $.fn.modal

  $.fn.modal = function (option, _relatedTarget) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.modal')
      var options = $.extend({}, Modal.DEFAULTS, $this.data(), typeof option == 'object' && option)

      if (!data) $this.data('bs.modal', (data = new Modal(this, options)))
      if (typeof option == 'string') data[option](_relatedTarget)
      else if (options.show) data.show(_relatedTarget)
    })
  }

  $.fn.modal.Constructor = Modal


  // MODAL NO CONFLICT
  // =================

  $.fn.modal.noConflict = function () {
    $.fn.modal = old
    return this
  }


  // MODAL DATA-API
  // ==============

  $(document).on('click.bs.modal.data-api', '[data-toggle="modal"]', function (e) {
    var $this   = $(this)
    var href    = $this.attr('href')
    var $target = $($this.attr('data-target') || (href && href.replace(/.*(?=#[^\s]+$)/, ''))) //strip for ie7
    var option  = $target.data('bs.modal') ? 'toggle' : $.extend({ remote: !/#/.test(href) && href }, $target.data(), $this.data())

    if ($this.is('a')) e.preventDefault()

    $target
      .modal(option, this)
      .one('hide', function () {
        $this.is(':visible') && $this.focus()
      })
  })

  $(document)
    .on('show.bs.modal', '.modal', function () { $(document.body).addClass('modal-open') })
    .on('hidden.bs.modal', '.modal', function () { $(document.body).removeClass('modal-open') })

}(jQuery);
/* ========================================================================
 * Bootstrap: dropdown.js v3.1.1
 * http://getbootstrap.com/javascript/#dropdowns
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // DROPDOWN CLASS DEFINITION
  // =========================

  var backdrop = '.dropdown-backdrop'
  var toggle   = '[data-toggle=dropdown]'
  var Dropdown = function (element) {
    $(element).on('click.bs.dropdown', this.toggle)
  }

  Dropdown.prototype.toggle = function (e) {
    var $this = $(this)

    if ($this.is('.disabled, :disabled')) return

    var $parent  = getParent($this)
    var isActive = $parent.hasClass('open')

    clearMenus()

    if (!isActive) {
      if ('ontouchstart' in document.documentElement && !$parent.closest('.navbar-nav').length) {
        // if mobile we use a backdrop because click events don't delegate
        $('<div class="dropdown-backdrop"/>').insertAfter($(this)).on('click', clearMenus)
      }

      var relatedTarget = { relatedTarget: this }
      $parent.trigger(e = $.Event('show.bs.dropdown', relatedTarget))

      if (e.isDefaultPrevented()) return

      $parent
        .toggleClass('open')
        .trigger('shown.bs.dropdown', relatedTarget)

      $this.focus()
    }

    return false
  }

  Dropdown.prototype.keydown = function (e) {
    if (!/(38|40|27)/.test(e.keyCode)) return

    var $this = $(this)

    e.preventDefault()
    e.stopPropagation()

    if ($this.is('.disabled, :disabled')) return

    var $parent  = getParent($this)
    var isActive = $parent.hasClass('open')

    if (!isActive || (isActive && e.keyCode == 27)) {
      if (e.which == 27) $parent.find(toggle).focus()
      return $this.click()
    }

    var desc = ' li:not(.divider):visible a'
    var $items = $parent.find('[role=menu]' + desc + ', [role=listbox]' + desc)

    if (!$items.length) return

    var index = $items.index($items.filter(':focus'))

    if (e.keyCode == 38 && index > 0)                 index--                        // up
    if (e.keyCode == 40 && index < $items.length - 1) index++                        // down
    if (!~index)                                      index = 0

    $items.eq(index).focus()
  }

  function clearMenus(e) {
    $(backdrop).remove()
    $(toggle).each(function () {
      var $parent = getParent($(this))
      var relatedTarget = { relatedTarget: this }
      if (!$parent.hasClass('open')) return
      $parent.trigger(e = $.Event('hide.bs.dropdown', relatedTarget))
      if (e.isDefaultPrevented()) return
      $parent.removeClass('open').trigger('hidden.bs.dropdown', relatedTarget)
    })
  }

  function getParent($this) {
    var selector = $this.attr('data-target')

    if (!selector) {
      selector = $this.attr('href')
      selector = selector && /#[A-Za-z]/.test(selector) && selector.replace(/.*(?=#[^\s]*$)/, '') //strip for ie7
    }

    var $parent = selector && $(selector)

    return $parent && $parent.length ? $parent : $this.parent()
  }


  // DROPDOWN PLUGIN DEFINITION
  // ==========================

  var old = $.fn.dropdown

  $.fn.dropdown = function (option) {
    return this.each(function () {
      var $this = $(this)
      var data  = $this.data('bs.dropdown')

      if (!data) $this.data('bs.dropdown', (data = new Dropdown(this)))
      if (typeof option == 'string') data[option].call($this)
    })
  }

  $.fn.dropdown.Constructor = Dropdown


  // DROPDOWN NO CONFLICT
  // ====================

  $.fn.dropdown.noConflict = function () {
    $.fn.dropdown = old
    return this
  }


  // APPLY TO STANDARD DROPDOWN ELEMENTS
  // ===================================

  $(document)
    .on('click.bs.dropdown.data-api', clearMenus)
    .on('click.bs.dropdown.data-api', '.dropdown form', function (e) { e.stopPropagation() })
    .on('click.bs.dropdown.data-api', toggle, Dropdown.prototype.toggle)
    .on('keydown.bs.dropdown.data-api', toggle + ', [role=menu], [role=listbox]', Dropdown.prototype.keydown)

}(jQuery);
/* ========================================================================
 * Bootstrap: scrollspy.js v3.1.1
 * http://getbootstrap.com/javascript/#scrollspy
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // SCROLLSPY CLASS DEFINITION
  // ==========================

  function ScrollSpy(element, options) {
    var href
    var process  = $.proxy(this.process, this)

    this.$element       = $(element).is('body') ? $(window) : $(element)
    this.$body          = $('body')
    this.$scrollElement = this.$element.on('scroll.bs.scroll-spy.data-api', process)
    this.options        = $.extend({}, ScrollSpy.DEFAULTS, options)
    this.selector       = (this.options.target
      || ((href = $(element).attr('href')) && href.replace(/.*(?=#[^\s]+$)/, '')) //strip for ie7
      || '') + ' .nav li > a'
    this.offsets        = $([])
    this.targets        = $([])
    this.activeTarget   = null

    this.refresh()
    this.process()
  }

  ScrollSpy.DEFAULTS = {
    offset: 10
  }

  ScrollSpy.prototype.refresh = function () {
    var offsetMethod = this.$element[0] == window ? 'offset' : 'position'

    this.offsets = $([])
    this.targets = $([])

    var self     = this
    var $targets = this.$body
      .find(this.selector)
      .map(function () {
        var $el   = $(this)
        var href  = $el.data('target') || $el.attr('href')
        var $href = /^#./.test(href) && $(href)

        return ($href
          && $href.length
          && $href.is(':visible')
          && [[ $href[offsetMethod]().top + (!$.isWindow(self.$scrollElement.get(0)) && self.$scrollElement.scrollTop()), href ]]) || null
      })
      .sort(function (a, b) { return a[0] - b[0] })
      .each(function () {
        self.offsets.push(this[0])
        self.targets.push(this[1])
      })
  }

  ScrollSpy.prototype.process = function () {
    var scrollTop    = this.$scrollElement.scrollTop() + this.options.offset
    var scrollHeight = this.$scrollElement[0].scrollHeight || this.$body[0].scrollHeight
    var maxScroll    = scrollHeight - this.$scrollElement.height()
    var offsets      = this.offsets
    var targets      = this.targets
    var activeTarget = this.activeTarget
    var i

    if (scrollTop >= maxScroll) {
      return activeTarget != (i = targets.last()[0]) && this.activate(i)
    }

    if (activeTarget && scrollTop <= offsets[0]) {
      return activeTarget != (i = targets[0]) && this.activate(i)
    }

    for (i = offsets.length; i--;) {
      activeTarget != targets[i]
        && scrollTop >= offsets[i]
        && (!offsets[i + 1] || scrollTop <= offsets[i + 1])
        && this.activate( targets[i] )
    }
  }

  ScrollSpy.prototype.activate = function (target) {
    this.activeTarget = target

    $(this.selector)
      .parentsUntil(this.options.target, '.active')
      .removeClass('active')

    var selector = this.selector +
        '[data-target="' + target + '"],' +
        this.selector + '[href="' + target + '"]'

    var active = $(selector)
      .parents('li')
      .addClass('active')

    if (active.parent('.dropdown-menu').length) {
      active = active
        .closest('li.dropdown')
        .addClass('active')
    }

    active.trigger('activate.bs.scrollspy')
  }


  // SCROLLSPY PLUGIN DEFINITION
  // ===========================

  var old = $.fn.scrollspy

  $.fn.scrollspy = function (option) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.scrollspy')
      var options = typeof option == 'object' && option

      if (!data) $this.data('bs.scrollspy', (data = new ScrollSpy(this, options)))
      if (typeof option == 'string') data[option]()
    })
  }

  $.fn.scrollspy.Constructor = ScrollSpy


  // SCROLLSPY NO CONFLICT
  // =====================

  $.fn.scrollspy.noConflict = function () {
    $.fn.scrollspy = old
    return this
  }


  // SCROLLSPY DATA-API
  // ==================

  $(window).on('load', function () {
    $('[data-spy="scroll"]').each(function () {
      var $spy = $(this)
      $spy.scrollspy($spy.data())
    })
  })

}(jQuery);
/* ========================================================================
 * Bootstrap: tab.js v3.1.1
 * http://getbootstrap.com/javascript/#tabs
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // TAB CLASS DEFINITION
  // ====================

  var Tab = function (element) {
    this.element = $(element)
  }

  Tab.prototype.show = function () {
    var $this    = this.element
    var $ul      = $this.closest('ul:not(.dropdown-menu)')
    var selector = $this.data('target')

    if (!selector) {
      selector = $this.attr('href')
      selector = selector && selector.replace(/.*(?=#[^\s]*$)/, '') //strip for ie7
    }

    if ($this.parent('li').hasClass('active')) return

    var previous = $ul.find('.active:last a')[0]
    var e        = $.Event('show.bs.tab', {
      relatedTarget: previous
    })

    $this.trigger(e)

    if (e.isDefaultPrevented()) return

    var $target = $(selector)

    this.activate($this.parent('li'), $ul)
    this.activate($target, $target.parent(), function () {
      $this.trigger({
        type: 'shown.bs.tab',
        relatedTarget: previous
      })
    })
  }

  Tab.prototype.activate = function (element, container, callback) {
    var $active    = container.find('> .active')
    var transition = callback
      && $.support.transition
      && $active.hasClass('fade')

    function next() {
      $active
        .removeClass('active')
        .find('> .dropdown-menu > .active')
        .removeClass('active')

      element.addClass('active')

      if (transition) {
        element[0].offsetWidth // reflow for transition
        element.addClass('in')
      } else {
        element.removeClass('fade')
      }

      if (element.parent('.dropdown-menu')) {
        element.closest('li.dropdown').addClass('active')
      }

      callback && callback()
    }

    transition ?
      $active
        .one($.support.transition.end, next)
        .emulateTransitionEnd(150) :
      next()

    $active.removeClass('in')
  }


  // TAB PLUGIN DEFINITION
  // =====================

  var old = $.fn.tab

  $.fn.tab = function ( option ) {
    return this.each(function () {
      var $this = $(this)
      var data  = $this.data('bs.tab')

      if (!data) $this.data('bs.tab', (data = new Tab(this)))
      if (typeof option == 'string') data[option]()
    })
  }

  $.fn.tab.Constructor = Tab


  // TAB NO CONFLICT
  // ===============

  $.fn.tab.noConflict = function () {
    $.fn.tab = old
    return this
  }


  // TAB DATA-API
  // ============

  $(document).on('click.bs.tab.data-api', '[data-toggle="tab"], [data-toggle="pill"]', function (e) {
    e.preventDefault()
    $(this).tab('show')
  })

}(jQuery);
/* ========================================================================
 * Bootstrap: tooltip.js v3.1.1
 * http://getbootstrap.com/javascript/#tooltip
 * Inspired by the original jQuery.tipsy by Jason Frame
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // TOOLTIP PUBLIC CLASS DEFINITION
  // ===============================

  var Tooltip = function (element, options) {
    this.type       =
    this.options    =
    this.enabled    =
    this.timeout    =
    this.hoverState =
    this.$element   = null

    this.init('tooltip', element, options)
  }

  Tooltip.DEFAULTS = {
    animation: true,
    placement: 'top',
    selector: false,
    template: '<div class="tooltip"><div class="tooltip-arrow"></div><div class="tooltip-inner"></div></div>',
    trigger: 'hover focus',
    title: '',
    delay: 0,
    html: false,
    container: false
  }

  Tooltip.prototype.init = function (type, element, options) {
    this.enabled  = true
    this.type     = type
    this.$element = $(element)
    this.options  = this.getOptions(options)

    var triggers = this.options.trigger.split(' ')

    for (var i = triggers.length; i--;) {
      var trigger = triggers[i]

      if (trigger == 'click') {
        this.$element.on('click.' + this.type, this.options.selector, $.proxy(this.toggle, this))
      } else if (trigger != 'manual') {
        var eventIn  = trigger == 'hover' ? 'mouseenter' : 'focusin'
        var eventOut = trigger == 'hover' ? 'mouseleave' : 'focusout'

        this.$element.on(eventIn  + '.' + this.type, this.options.selector, $.proxy(this.enter, this))
        this.$element.on(eventOut + '.' + this.type, this.options.selector, $.proxy(this.leave, this))
      }
    }

    this.options.selector ?
      (this._options = $.extend({}, this.options, { trigger: 'manual', selector: '' })) :
      this.fixTitle()
  }

  Tooltip.prototype.getDefaults = function () {
    return Tooltip.DEFAULTS
  }

  Tooltip.prototype.getOptions = function (options) {
    options = $.extend({}, this.getDefaults(), this.$element.data(), options)

    if (options.delay && typeof options.delay == 'number') {
      options.delay = {
        show: options.delay,
        hide: options.delay
      }
    }

    return options
  }

  Tooltip.prototype.getDelegateOptions = function () {
    var options  = {}
    var defaults = this.getDefaults()

    this._options && $.each(this._options, function (key, value) {
      if (defaults[key] != value) options[key] = value
    })

    return options
  }

  Tooltip.prototype.enter = function (obj) {
    var self = obj instanceof this.constructor ?
      obj : $(obj.currentTarget)[this.type](this.getDelegateOptions()).data('bs.' + this.type)

    clearTimeout(self.timeout)

    self.hoverState = 'in'

    if (!self.options.delay || !self.options.delay.show) return self.show()

    self.timeout = setTimeout(function () {
      if (self.hoverState == 'in') self.show()
    }, self.options.delay.show)
  }

  Tooltip.prototype.leave = function (obj) {
    var self = obj instanceof this.constructor ?
      obj : $(obj.currentTarget)[this.type](this.getDelegateOptions()).data('bs.' + this.type)

    clearTimeout(self.timeout)

    self.hoverState = 'out'

    if (!self.options.delay || !self.options.delay.hide) return self.hide()

    self.timeout = setTimeout(function () {
      if (self.hoverState == 'out') self.hide()
    }, self.options.delay.hide)
  }

  Tooltip.prototype.show = function () {
    var e = $.Event('show.bs.' + this.type)

    if (this.hasContent() && this.enabled) {
      this.$element.trigger(e)

      if (e.isDefaultPrevented()) return
      var that = this;

      var $tip = this.tip()

      this.setContent()

      if (this.options.animation) $tip.addClass('fade')

      var placement = typeof this.options.placement == 'function' ?
        this.options.placement.call(this, $tip[0], this.$element[0]) :
        this.options.placement

      var autoToken = /\s?auto?\s?/i
      var autoPlace = autoToken.test(placement)
      if (autoPlace) placement = placement.replace(autoToken, '') || 'top'

      $tip
        .detach()
        .css({ top: 0, left: 0, display: 'block' })
        .addClass(placement)

      this.options.container ? $tip.appendTo(this.options.container) : $tip.insertAfter(this.$element)

      var pos          = this.getPosition()
      var actualWidth  = $tip[0].offsetWidth
      var actualHeight = $tip[0].offsetHeight

      if (autoPlace) {
        var $parent = this.$element.parent()

        var orgPlacement = placement
        var docScroll    = document.documentElement.scrollTop || document.body.scrollTop
        var parentWidth  = this.options.container == 'body' ? window.innerWidth  : $parent.outerWidth()
        var parentHeight = this.options.container == 'body' ? window.innerHeight : $parent.outerHeight()
        var parentLeft   = this.options.container == 'body' ? 0 : $parent.offset().left

        placement = placement == 'bottom' && pos.top   + pos.height  + actualHeight - docScroll > parentHeight  ? 'top'    :
                    placement == 'top'    && pos.top   - docScroll   - actualHeight < 0                         ? 'bottom' :
                    placement == 'right'  && pos.right + actualWidth > parentWidth                              ? 'left'   :
                    placement == 'left'   && pos.left  - actualWidth < parentLeft                               ? 'right'  :
                    placement

        $tip
          .removeClass(orgPlacement)
          .addClass(placement)
      }

      var calculatedOffset = this.getCalculatedOffset(placement, pos, actualWidth, actualHeight)

      this.applyPlacement(calculatedOffset, placement)
      this.hoverState = null

      var complete = function() {
        that.$element.trigger('shown.bs.' + that.type)
      }

      $.support.transition && this.$tip.hasClass('fade') ?
        $tip
          .one($.support.transition.end, complete)
          .emulateTransitionEnd(150) :
        complete()
    }
  }

  Tooltip.prototype.applyPlacement = function (offset, placement) {
    var replace
    var $tip   = this.tip()
    var width  = $tip[0].offsetWidth
    var height = $tip[0].offsetHeight

    // manually read margins because getBoundingClientRect includes difference
    var marginTop = parseInt($tip.css('margin-top'), 10)
    var marginLeft = parseInt($tip.css('margin-left'), 10)

    // we must check for NaN for ie 8/9
    if (isNaN(marginTop))  marginTop  = 0
    if (isNaN(marginLeft)) marginLeft = 0

    offset.top  = offset.top  + marginTop
    offset.left = offset.left + marginLeft

    // $.fn.offset doesn't round pixel values
    // so we use setOffset directly with our own function B-0
    $.offset.setOffset($tip[0], $.extend({
      using: function (props) {
        $tip.css({
          top: Math.round(props.top),
          left: Math.round(props.left)
        })
      }
    }, offset), 0)

    $tip.addClass('in')

    // check to see if placing tip in new offset caused the tip to resize itself
    var actualWidth  = $tip[0].offsetWidth
    var actualHeight = $tip[0].offsetHeight

    if (placement == 'top' && actualHeight != height) {
      replace = true
      offset.top = offset.top + height - actualHeight
    }

    if (/bottom|top/.test(placement)) {
      var delta = 0

      if (offset.left < 0) {
        delta       = offset.left * -2
        offset.left = 0

        $tip.offset(offset)

        actualWidth  = $tip[0].offsetWidth
        actualHeight = $tip[0].offsetHeight
      }

      this.replaceArrow(delta - width + actualWidth, actualWidth, 'left')
    } else {
      this.replaceArrow(actualHeight - height, actualHeight, 'top')
    }

    if (replace) $tip.offset(offset)
  }

  Tooltip.prototype.replaceArrow = function (delta, dimension, position) {
    this.arrow().css(position, delta ? (50 * (1 - delta / dimension) + '%') : '')
  }

  Tooltip.prototype.setContent = function () {
    var $tip  = this.tip()
    var title = this.getTitle()

    $tip.find('.tooltip-inner')[this.options.html ? 'html' : 'text'](title)
    $tip.removeClass('fade in top bottom left right')
  }

  Tooltip.prototype.hide = function () {
    var that = this
    var $tip = this.tip()
    var e    = $.Event('hide.bs.' + this.type)

    function complete() {
      if (that.hoverState != 'in') $tip.detach()
      that.$element.trigger('hidden.bs.' + that.type)
    }

    this.$element.trigger(e)

    if (e.isDefaultPrevented()) return

    $tip.removeClass('in')

    $.support.transition && this.$tip.hasClass('fade') ?
      $tip
        .one($.support.transition.end, complete)
        .emulateTransitionEnd(150) :
      complete()

    this.hoverState = null

    return this
  }

  Tooltip.prototype.fixTitle = function () {
    var $e = this.$element
    if ($e.attr('title') || typeof($e.attr('data-original-title')) != 'string') {
      $e.attr('data-original-title', $e.attr('title') || '').attr('title', '')
    }
  }

  Tooltip.prototype.hasContent = function () {
    return this.getTitle()
  }

  Tooltip.prototype.getPosition = function () {
    var el = this.$element[0]
    return $.extend({}, (typeof el.getBoundingClientRect == 'function') ? el.getBoundingClientRect() : {
      width: el.offsetWidth,
      height: el.offsetHeight
    }, this.$element.offset())
  }

  Tooltip.prototype.getCalculatedOffset = function (placement, pos, actualWidth, actualHeight) {
    return placement == 'bottom' ? { top: pos.top + pos.height,   left: pos.left + pos.width / 2 - actualWidth / 2  } :
           placement == 'top'    ? { top: pos.top - actualHeight, left: pos.left + pos.width / 2 - actualWidth / 2  } :
           placement == 'left'   ? { top: pos.top + pos.height / 2 - actualHeight / 2, left: pos.left - actualWidth } :
        /* placement == 'right' */ { top: pos.top + pos.height / 2 - actualHeight / 2, left: pos.left + pos.width   }
  }

  Tooltip.prototype.getTitle = function () {
    var title
    var $e = this.$element
    var o  = this.options

    title = $e.attr('data-original-title')
      || (typeof o.title == 'function' ? o.title.call($e[0]) :  o.title)

    return title
  }

  Tooltip.prototype.tip = function () {
    return this.$tip = this.$tip || $(this.options.template)
  }

  Tooltip.prototype.arrow = function () {
    return this.$arrow = this.$arrow || this.tip().find('.tooltip-arrow')
  }

  Tooltip.prototype.validate = function () {
    if (!this.$element[0].parentNode) {
      this.hide()
      this.$element = null
      this.options  = null
    }
  }

  Tooltip.prototype.enable = function () {
    this.enabled = true
  }

  Tooltip.prototype.disable = function () {
    this.enabled = false
  }

  Tooltip.prototype.toggleEnabled = function () {
    this.enabled = !this.enabled
  }

  Tooltip.prototype.toggle = function (e) {
    var self = e ? $(e.currentTarget)[this.type](this.getDelegateOptions()).data('bs.' + this.type) : this
    self.tip().hasClass('in') ? self.leave(self) : self.enter(self)
  }

  Tooltip.prototype.destroy = function () {
    clearTimeout(this.timeout)
    this.hide().$element.off('.' + this.type).removeData('bs.' + this.type)
  }


  // TOOLTIP PLUGIN DEFINITION
  // =========================

  var old = $.fn.tooltip

  $.fn.tooltip = function (option) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.tooltip')
      var options = typeof option == 'object' && option

      if (!data && option == 'destroy') return
      if (!data) $this.data('bs.tooltip', (data = new Tooltip(this, options)))
      if (typeof option == 'string') data[option]()
    })
  }

  $.fn.tooltip.Constructor = Tooltip


  // TOOLTIP NO CONFLICT
  // ===================

  $.fn.tooltip.noConflict = function () {
    $.fn.tooltip = old
    return this
  }

}(jQuery);
/* ========================================================================
 * Bootstrap: popover.js v3.1.1
 * http://getbootstrap.com/javascript/#popovers
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // POPOVER PUBLIC CLASS DEFINITION
  // ===============================

  var Popover = function (element, options) {
    this.init('popover', element, options)
  }

  if (!$.fn.tooltip) throw new Error('Popover requires tooltip.js')

  Popover.DEFAULTS = $.extend({}, $.fn.tooltip.Constructor.DEFAULTS, {
    placement: 'right',
    trigger: 'click',
    content: '',
    template: '<div class="popover"><div class="arrow"></div><h3 class="popover-title"></h3><div class="popover-content"></div></div>'
  })


  // NOTE: POPOVER EXTENDS tooltip.js
  // ================================

  Popover.prototype = $.extend({}, $.fn.tooltip.Constructor.prototype)

  Popover.prototype.constructor = Popover

  Popover.prototype.getDefaults = function () {
    return Popover.DEFAULTS
  }

  Popover.prototype.setContent = function () {
    var $tip    = this.tip()
    var title   = this.getTitle()
    var content = this.getContent()

    $tip.find('.popover-title')[this.options.html ? 'html' : 'text'](title)
    $tip.find('.popover-content')[ // we use append for html objects to maintain js events
      this.options.html ? (typeof content == 'string' ? 'html' : 'append') : 'text'
    ](content)

    $tip.removeClass('fade top bottom left right in')

    // IE8 doesn't accept hiding via the `:empty` pseudo selector, we have to do
    // this manually by checking the contents.
    if (!$tip.find('.popover-title').html()) $tip.find('.popover-title').hide()
  }

  Popover.prototype.hasContent = function () {
    return this.getTitle() || this.getContent()
  }

  Popover.prototype.getContent = function () {
    var $e = this.$element
    var o  = this.options

    return $e.attr('data-content')
      || (typeof o.content == 'function' ?
            o.content.call($e[0]) :
            o.content)
  }

  Popover.prototype.arrow = function () {
    return this.$arrow = this.$arrow || this.tip().find('.arrow')
  }

  Popover.prototype.tip = function () {
    if (!this.$tip) this.$tip = $(this.options.template)
    return this.$tip
  }


  // POPOVER PLUGIN DEFINITION
  // =========================

  var old = $.fn.popover

  $.fn.popover = function (option) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.popover')
      var options = typeof option == 'object' && option

      if (!data && option == 'destroy') return
      if (!data) $this.data('bs.popover', (data = new Popover(this, options)))
      if (typeof option == 'string') data[option]()
    })
  }

  $.fn.popover.Constructor = Popover


  // POPOVER NO CONFLICT
  // ===================

  $.fn.popover.noConflict = function () {
    $.fn.popover = old
    return this
  }

}(jQuery);
/* ========================================================================
 * Bootstrap: button.js v3.1.1
 * http://getbootstrap.com/javascript/#buttons
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // BUTTON PUBLIC CLASS DEFINITION
  // ==============================

  var Button = function (element, options) {
    this.$element  = $(element)
    this.options   = $.extend({}, Button.DEFAULTS, options)
    this.isLoading = false
  }

  Button.DEFAULTS = {
    loadingText: 'loading...'
  }

  Button.prototype.setState = function (state) {
    var d    = 'disabled'
    var $el  = this.$element
    var val  = $el.is('input') ? 'val' : 'html'
    var data = $el.data()

    state = state + 'Text'

    if (!data.resetText) $el.data('resetText', $el[val]())

    $el[val](data[state] || this.options[state])

    // push to event loop to allow forms to submit
    setTimeout($.proxy(function () {
      if (state == 'loadingText') {
        this.isLoading = true
        $el.addClass(d).attr(d, d)
      } else if (this.isLoading) {
        this.isLoading = false
        $el.removeClass(d).removeAttr(d)
      }
    }, this), 0)
  }

  Button.prototype.toggle = function () {
    var changed = true
    var $parent = this.$element.closest('[data-toggle="buttons"]')

    if ($parent.length) {
      var $input = this.$element.find('input')
      if ($input.prop('type') == 'radio') {
        if ($input.prop('checked') && this.$element.hasClass('active')) changed = false
        else $parent.find('.active').removeClass('active')
      }
      if (changed) $input.prop('checked', !this.$element.hasClass('active')).trigger('change')
    }

    if (changed) this.$element.toggleClass('active')
  }


  // BUTTON PLUGIN DEFINITION
  // ========================

  var old = $.fn.button

  $.fn.button = function (option) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.button')
      var options = typeof option == 'object' && option

      if (!data) $this.data('bs.button', (data = new Button(this, options)))

      if (option == 'toggle') data.toggle()
      else if (option) data.setState(option)
    })
  }

  $.fn.button.Constructor = Button


  // BUTTON NO CONFLICT
  // ==================

  $.fn.button.noConflict = function () {
    $.fn.button = old
    return this
  }


  // BUTTON DATA-API
  // ===============

  $(document).on('click.bs.button.data-api', '[data-toggle^=button]', function (e) {
    var $btn = $(e.target)
    if (!$btn.hasClass('btn')) $btn = $btn.closest('.btn')
    $btn.button('toggle')
    e.preventDefault()
  })

}(jQuery);
/* ========================================================================
 * Bootstrap: collapse.js v3.1.1
 * http://getbootstrap.com/javascript/#collapse
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // COLLAPSE PUBLIC CLASS DEFINITION
  // ================================

  var Collapse = function (element, options) {
    this.$element      = $(element)
    this.options       = $.extend({}, Collapse.DEFAULTS, options)
    this.transitioning = null

    if (this.options.parent) this.$parent = $(this.options.parent)
    if (this.options.toggle) this.toggle()
  }

  Collapse.DEFAULTS = {
    toggle: true
  }

  Collapse.prototype.dimension = function () {
    var hasWidth = this.$element.hasClass('width')
    return hasWidth ? 'width' : 'height'
  }

  Collapse.prototype.show = function () {
    if (this.transitioning || this.$element.hasClass('in')) return

    var startEvent = $.Event('show.bs.collapse')
    this.$element.trigger(startEvent)
    if (startEvent.isDefaultPrevented()) return

    var actives = this.$parent && this.$parent.find('> .panel > .in')

    if (actives && actives.length) {
      var hasData = actives.data('bs.collapse')
      if (hasData && hasData.transitioning) return
      actives.collapse('hide')
      hasData || actives.data('bs.collapse', null)
    }

    var dimension = this.dimension()

    this.$element
      .removeClass('collapse')
      .addClass('collapsing')
      [dimension](0)

    this.transitioning = 1

    var complete = function () {
      this.$element
        .removeClass('collapsing')
        .addClass('collapse in')
        [dimension]('auto')
      this.transitioning = 0
      this.$element.trigger('shown.bs.collapse')
    }

    if (!$.support.transition) return complete.call(this)

    var scrollSize = $.camelCase(['scroll', dimension].join('-'))

    this.$element
      .one($.support.transition.end, $.proxy(complete, this))
      .emulateTransitionEnd(350)
      [dimension](this.$element[0][scrollSize])
  }

  Collapse.prototype.hide = function () {
    if (this.transitioning || !this.$element.hasClass('in')) return

    var startEvent = $.Event('hide.bs.collapse')
    this.$element.trigger(startEvent)
    if (startEvent.isDefaultPrevented()) return

    var dimension = this.dimension()

    this.$element
      [dimension](this.$element[dimension]())
      [0].offsetHeight

    this.$element
      .addClass('collapsing')
      .removeClass('collapse')
      .removeClass('in')

    this.transitioning = 1

    var complete = function () {
      this.transitioning = 0
      this.$element
        .trigger('hidden.bs.collapse')
        .removeClass('collapsing')
        .addClass('collapse')
    }

    if (!$.support.transition) return complete.call(this)

    this.$element
      [dimension](0)
      .one($.support.transition.end, $.proxy(complete, this))
      .emulateTransitionEnd(350)
  }

  Collapse.prototype.toggle = function () {
    this[this.$element.hasClass('in') ? 'hide' : 'show']()
  }


  // COLLAPSE PLUGIN DEFINITION
  // ==========================

  var old = $.fn.collapse

  $.fn.collapse = function (option) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.collapse')
      var options = $.extend({}, Collapse.DEFAULTS, $this.data(), typeof option == 'object' && option)

      if (!data && options.toggle && option == 'show') option = !option
      if (!data) $this.data('bs.collapse', (data = new Collapse(this, options)))
      if (typeof option == 'string') data[option]()
    })
  }

  $.fn.collapse.Constructor = Collapse


  // COLLAPSE NO CONFLICT
  // ====================

  $.fn.collapse.noConflict = function () {
    $.fn.collapse = old
    return this
  }


  // COLLAPSE DATA-API
  // =================

  $(document).on('click.bs.collapse.data-api', '[data-toggle=collapse]', function (e) {
    var $this   = $(this), href
    var target  = $this.attr('data-target')
        || e.preventDefault()
        || (href = $this.attr('href')) && href.replace(/.*(?=#[^\s]+$)/, '') //strip for ie7
    var $target = $(target)
    var data    = $target.data('bs.collapse')
    var option  = data ? 'toggle' : $this.data()
    var parent  = $this.attr('data-parent')
    var $parent = parent && $(parent)

    if (!data || !data.transitioning) {
      if ($parent) $parent.find('[data-toggle=collapse][data-parent="' + parent + '"]').not($this).addClass('collapsed')
      $this[$target.hasClass('in') ? 'addClass' : 'removeClass']('collapsed')
    }

    $target.collapse(option)
  })

}(jQuery);
/* ========================================================================
 * Bootstrap: carousel.js v3.1.1
 * http://getbootstrap.com/javascript/#carousel
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // CAROUSEL CLASS DEFINITION
  // =========================

  var Carousel = function (element, options) {
    this.$element    = $(element)
    this.$indicators = this.$element.find('.carousel-indicators')
    this.options     = options
    this.paused      =
    this.sliding     =
    this.interval    =
    this.$active     =
    this.$items      = null

    this.options.pause == 'hover' && this.$element
      .on('mouseenter', $.proxy(this.pause, this))
      .on('mouseleave', $.proxy(this.cycle, this))
  }

  Carousel.DEFAULTS = {
    interval: 5000,
    pause: 'hover',
    wrap: true
  }

  Carousel.prototype.cycle =  function (e) {
    e || (this.paused = false)

    this.interval && clearInterval(this.interval)

    this.options.interval
      && !this.paused
      && (this.interval = setInterval($.proxy(this.next, this), this.options.interval))

    return this
  }

  Carousel.prototype.getActiveIndex = function () {
    this.$active = this.$element.find('.item.active')
    this.$items  = this.$active.parent().children()

    return this.$items.index(this.$active)
  }

  Carousel.prototype.to = function (pos) {
    var that        = this
    var activeIndex = this.getActiveIndex()

    if (pos > (this.$items.length - 1) || pos < 0) return

    if (this.sliding)       return this.$element.one('slid.bs.carousel', function () { that.to(pos) })
    if (activeIndex == pos) return this.pause().cycle()

    return this.slide(pos > activeIndex ? 'next' : 'prev', $(this.$items[pos]))
  }

  Carousel.prototype.pause = function (e) {
    e || (this.paused = true)

    if (this.$element.find('.next, .prev').length && $.support.transition) {
      this.$element.trigger($.support.transition.end)
      this.cycle(true)
    }

    this.interval = clearInterval(this.interval)

    return this
  }

  Carousel.prototype.next = function () {
    if (this.sliding) return
    return this.slide('next')
  }

  Carousel.prototype.prev = function () {
    if (this.sliding) return
    return this.slide('prev')
  }

  Carousel.prototype.slide = function (type, next) {
    var $active   = this.$element.find('.item.active')
    var $next     = next || $active[type]()
    var isCycling = this.interval
    var direction = type == 'next' ? 'left' : 'right'
    var fallback  = type == 'next' ? 'first' : 'last'
    var that      = this

    if (!$next.length) {
      if (!this.options.wrap) return
      $next = this.$element.find('.item')[fallback]()
    }

    if ($next.hasClass('active')) return this.sliding = false

    var e = $.Event('slide.bs.carousel', { relatedTarget: $next[0], direction: direction })
    this.$element.trigger(e)
    if (e.isDefaultPrevented()) return

    this.sliding = true

    isCycling && this.pause()

    if (this.$indicators.length) {
      this.$indicators.find('.active').removeClass('active')
      this.$element.one('slid.bs.carousel', function () {
        var $nextIndicator = $(that.$indicators.children()[that.getActiveIndex()])
        $nextIndicator && $nextIndicator.addClass('active')
      })
    }

    if ($.support.transition && this.$element.hasClass('slide')) {
      $next.addClass(type)
      $next[0].offsetWidth // force reflow
      $active.addClass(direction)
      $next.addClass(direction)
      $active
        .one($.support.transition.end, function () {
          $next.removeClass([type, direction].join(' ')).addClass('active')
          $active.removeClass(['active', direction].join(' '))
          that.sliding = false
          setTimeout(function () { that.$element.trigger('slid.bs.carousel') }, 0)
        })
        .emulateTransitionEnd($active.css('transition-duration').slice(0, -1) * 1000)
    } else {
      $active.removeClass('active')
      $next.addClass('active')
      this.sliding = false
      this.$element.trigger('slid.bs.carousel')
    }

    isCycling && this.cycle()

    return this
  }


  // CAROUSEL PLUGIN DEFINITION
  // ==========================

  var old = $.fn.carousel

  $.fn.carousel = function (option) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.carousel')
      var options = $.extend({}, Carousel.DEFAULTS, $this.data(), typeof option == 'object' && option)
      var action  = typeof option == 'string' ? option : options.slide

      if (!data) $this.data('bs.carousel', (data = new Carousel(this, options)))
      if (typeof option == 'number') data.to(option)
      else if (action) data[action]()
      else if (options.interval) data.pause().cycle()
    })
  }

  $.fn.carousel.Constructor = Carousel


  // CAROUSEL NO CONFLICT
  // ====================

  $.fn.carousel.noConflict = function () {
    $.fn.carousel = old
    return this
  }


  // CAROUSEL DATA-API
  // =================

  $(document).on('click.bs.carousel.data-api', '[data-slide], [data-slide-to]', function (e) {
    var $this   = $(this), href
    var $target = $($this.attr('data-target') || (href = $this.attr('href')) && href.replace(/.*(?=#[^\s]+$)/, '')) //strip for ie7
    var options = $.extend({}, $target.data(), $this.data())
    var slideIndex = $this.attr('data-slide-to')
    if (slideIndex) options.interval = false

    $target.carousel(options)

    if (slideIndex = $this.attr('data-slide-to')) {
      $target.data('bs.carousel').to(slideIndex)
    }

    e.preventDefault()
  })

  $(window).on('load', function () {
    $('[data-ride="carousel"]').each(function () {
      var $carousel = $(this)
      $carousel.carousel($carousel.data())
    })
  })

}(jQuery);
/* ========================================================================
 * Bootstrap: affix.js v3.1.1
 * http://getbootstrap.com/javascript/#affix
 * ========================================================================
 * Copyright 2011-2014 Twitter, Inc.
 * Licensed under MIT (https://github.com/twbs/bootstrap/blob/master/LICENSE)
 * ======================================================================== */



+function ($) {
  'use strict';

  // AFFIX CLASS DEFINITION
  // ======================

  var Affix = function (element, options) {
    this.options = $.extend({}, Affix.DEFAULTS, options)
    this.$window = $(window)
      .on('scroll.bs.affix.data-api', $.proxy(this.checkPosition, this))
      .on('click.bs.affix.data-api',  $.proxy(this.checkPositionWithEventLoop, this))

    this.$element     = $(element)
    this.affixed      =
    this.unpin        =
    this.pinnedOffset = null

    this.checkPosition()
  }

  Affix.RESET = 'affix affix-top affix-bottom'

  Affix.DEFAULTS = {
    offset: 0
  }

  Affix.prototype.getPinnedOffset = function () {
    if (this.pinnedOffset) return this.pinnedOffset
    this.$element.removeClass(Affix.RESET).addClass('affix')
    var scrollTop = this.$window.scrollTop()
    var position  = this.$element.offset()
    return (this.pinnedOffset = position.top - scrollTop)
  }

  Affix.prototype.checkPositionWithEventLoop = function () {
    setTimeout($.proxy(this.checkPosition, this), 1)
  }

  Affix.prototype.checkPosition = function () {
    if (!this.$element.is(':visible')) return

    var scrollHeight = $(document).height()
    var scrollTop    = this.$window.scrollTop()
    var position     = this.$element.offset()
    var offset       = this.options.offset
    var offsetTop    = offset.top
    var offsetBottom = offset.bottom

    if (this.affixed == 'top') position.top += scrollTop

    if (typeof offset != 'object')         offsetBottom = offsetTop = offset
    if (typeof offsetTop == 'function')    offsetTop    = offset.top(this.$element)
    if (typeof offsetBottom == 'function') offsetBottom = offset.bottom(this.$element)

    var affix = this.unpin   != null && (scrollTop + this.unpin <= position.top) ? false :
                offsetBottom != null && (position.top + this.$element.height() >= scrollHeight - offsetBottom) ? 'bottom' :
                offsetTop    != null && (scrollTop <= offsetTop) ? 'top' : false

    if (this.affixed === affix) return
    if (this.unpin) this.$element.css('top', '')

    var affixType = 'affix' + (affix ? '-' + affix : '')
    var e         = $.Event(affixType + '.bs.affix')

    this.$element.trigger(e)

    if (e.isDefaultPrevented()) return

    this.affixed = affix
    this.unpin = affix == 'bottom' ? this.getPinnedOffset() : null

    this.$element
      .removeClass(Affix.RESET)
      .addClass(affixType)
      .trigger($.Event(affixType.replace('affix', 'affixed')))

    if (affix == 'bottom') {
      this.$element.offset({ top: scrollHeight - offsetBottom - this.$element.height() })
    }
  }


  // AFFIX PLUGIN DEFINITION
  // =======================

  var old = $.fn.affix

  $.fn.affix = function (option) {
    return this.each(function () {
      var $this   = $(this)
      var data    = $this.data('bs.affix')
      var options = typeof option == 'object' && option

      if (!data) $this.data('bs.affix', (data = new Affix(this, options)))
      if (typeof option == 'string') data[option]()
    })
  }

  $.fn.affix.Constructor = Affix


  // AFFIX NO CONFLICT
  // =================

  $.fn.affix.noConflict = function () {
    $.fn.affix = old
    return this
  }


  // AFFIX DATA-API
  // ==============

  $(window).on('load', function () {
    $('[data-spy="affix"]').each(function () {
      var $spy = $(this)
      var data = $spy.data()

      data.offset = data.offset || {}

      if (data.offsetBottom) data.offset.bottom = data.offsetBottom
      if (data.offsetTop)    data.offset.top    = data.offsetTop

      $spy.affix(data)
    })
  })

}(jQuery);












(function() {
  var app, userAgent;

  window.isMac = false;

  window.isIpad = false;

  window.isIphone = false;

  window.isIOS = false;

  window.isAndroid = false;

  window.isMobile = false;

  window.isMSIE = false;

  window.isSafari = false;

  if (window.navigator && window.navigator.userAgent) {
    userAgent = window.navigator.userAgent;
    window.isMac = !!~userAgent.indexOf('Mac');
    window.isIpad = !!~userAgent.indexOf('iPad');
    window.isIphone = !!~userAgent.indexOf('iPhone');
    window.isIOS = window.isIpad || window.isIphone;
    window.isAndroid = !!~userAgent.indexOf('Android');
    window.isMobile = window.isIpad || window.isIphone || window.isAndroid;
    window.isMSIE = !!~userAgent.indexOf('MSIE');
    window.isSafari = !!~userAgent.indexOf('Safari') && !(!!~userAgent.indexOf('Chrome'));
  }

  app = angular.module('CodeApp', ['ngAnimate', 'ngCookies', 'ngResource', 'ngRoute', 'ngSanitize', 'ngTouch', 'ngMessages', 'runners', 'projects', 'languages', 'gists', 'favorites', 'featuredProjects', 'comments', 'users', 'ui.ace', 'ui.bootstrap', 'ui.utils', 'fromNowFilter', 'infinite-scroll', 'angular-loading-bar', 'i18nfilter', 'i18nmessages', 'angularLocalStorage', 'cgBusy']);

  app.config(function($sceDelegateProvider) {
    return $sceDelegateProvider.resourceUrlWhitelist(['self', 'http://out.localhost:3000/**', location.protocol + "//out." + location.host + "/**", '#{location.protocol}//#{location.host}/projects/e/**']);
  });

  app.run(function($rootScope, $location, $window) {
    $rootScope.$on('$locationChangeSuccess', function(event) {
      var page;
      page = $location.path();
      return $window.ga('send', 'pageview', {
        page: page
      });
    });
    return $rootScope.$on('$locationChangeStart', function(event) {
      $rootScope.description = null;
      return $rootScope.longTitle = null;
    });
  });

  app.run(function($rootScope, $window) {
    return $rootScope.isMobile = $window.isMobile;
  });

  window.signame = function(code) {
    var codemap, str;
    codemap = {
      1: "Hangup detected on controlling terminal",
      2: "Interrupt from keyboard",
      3: "Quit from keyboard",
      4: "Illegal Instruction",
      6: "Abort signal from abort(3)",
      8: "Floating point exception",
      9: "Kill signal",
      11: "Invalid memory reference",
      13: "Broken pipe: write to pipe with no readers",
      14: "Timer signal from alarm(2)",
      15: "Termination signal",
      16: "User-defined signal 1",
      17: "User-defined signal 2",
      18: "Child stopped or terminated",
      25: "File size limit exceeded"
    };
    str = codemap[code];
    if (str) {
      return str;
    } else {
      return "Unknown signal";
    }
  };

  window.TogetherJSConfig_getUserName = function() {
    return current_user && current_user.username;
  };

  window.TogetherJSConfig_getUserAvatar = function() {
    return current_user && current_user.image_url;
  };

}).call(this);
(function() {
  var module;

  module = angular.module("languages", []);

  module.factory("Language", function() {
    var Language, i, langinfos, language, languageId2LavelMap, languages, len;
    langinfos = {
      'c': ["#include <stdio.h>\nint main(void){\n", "    // ", "    ", "}\n", "c_cpp", "Main.c"],
      'cpp': ["#include <iostream>\nusing namespace std;\nint main(void){\n", "    // ", "    ", "}\n", "c_cpp", "Main.cpp"],
      'objective-c': ["#import <Foundation/Foundation.h>\nint main(void){\n    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];\n", "    // ", "    ", "    NSString *s = @\"XXXXXXXX\";\n    [[NSFileHandle fileHandleWithStandardOutput] writeData: [s dataUsingEncoding: NSUTF8StringEncoding]];\n    [pool release];\n    return 0;\n}", "objectivec", "Main.m"],
      'java': ["import java.util.*;\n\npublic class Main {\n    public static void main(String[] args) throws Exception {\n", "        // ", "        ", "        System.out.println(\"XXXXXXXX\");\n    }\n}\n", "java", "Main.java"],
      'kotlin': ["fun main(args: Array<String>) {\n", "    // ", "    ", "    println(\"XXXXXXXX\")\n}\n", "kotlin", "Main.kt"],
      'scala': ["object Main extends App{\n", "    // ", "    ", "    println(\"XXXXXXXX\")\n}\n", "scala", "Main.scala"],
      'swift': ["", "// ", "", "print(\"XXXXXXXX\")\n", "swift", "main.swift"],
      'csharp': ["public class Hello{\n    public static void Main(){\n", "        // ", "        ", "        System.Console.WriteLine(\"Hello C#\");\n    }\n}\n", "csharp", "Main.cs"],
      'fsharp': ["", "// ", "", "", "text", "Main.fs"],
      'go': ["package main\nimport \"fmt\"\nfunc main(){\n", "    // ", "    ", "    fmt.Println(\"XXXXXXXX\")\n}\n", "golang", "Main.go"],
      'haskell': ["", "-- ", "", "main = putStrLn \"XXXXXXXX\"", "haskell", "Main.hs"],
      'clojure': ["", "; ", "", "(println \"XXXXXXXX\")", "clojure", "Main.clj"],
      'd': ["", "// ", "", "import std.stdio;\nvoid main(){\n  writeln(\"XXXXXXXX\");\n}", "d", "Main.d"],
      'erlang': ["-module(main).\n-export([main/1]).\n", "%% ", "", "main([_]) ->\n    io:format(\"XXXXXXXX\"),\ninit:stop() .\n", "text", "main.erl"],
      'cobol': ["IDENTIFICATION DIVISION.\nprogram-id. Hello.\nprocedure division.\n", "# ", "", "display \"XXXXXXXX\".\n", "cobol", "Main.cob"],
      'vb': ["public class compiler\n  shared function Main as integer\n", "' ", "    ", "    Console.WriteLine (\"XXXXXXXX\")\n    return 0\n  End function\nend class\n", "vbscript", "Main.vb"],
      'perl': ["", "# ", "", "", "perl", "Main.pl"],
      'python': ["# coding: utf-8\n", "# ", "", "", "python", "Main.py"],
      'python3': ["# coding: utf-8\n", "# ", "", "", "python", "Main.py"],
      'ruby': ["", "# ", "", "", "ruby", "Main.rb"],
      'php': ["<?php\n", "// ", "", "?>\n", "php", "Main.php"],
      'bash': ["", "# ", "", "echo \"XXXXXXXX\"\n", "sh", "Main.sh"],
      'r': ["", "# ", "", "cat(\"XXXXXXXX\")\n", "r", "Main.R"],
      'javascript': ["process.stdin.resume();\nprocess.stdin.setEncoding('utf8');\n", "// ", "", "console.log(\"XXXXXXXX\")\n", "javascript", "Main.js"],
      'typescript': ["process.stdin.resume();\nprocess.stdin.setEncoding('utf8');\n", "// ", "", "console.log(\"XXXXXXXX\")\n", "typescript", "Main.ts"],
      'coffeescript': ["", "# ", "", "console.log(\"XXXXXXXX\")\n", "coffee", "Main.coffee"],
      'elixir': ["", "# ", "", "IO.puts \"XXXXXXXX\"\n", "elixir", "Main.exs"],
      'rust': ["", "// ", "", "fn main(){println!(\"XXXXXXXX\");}", "rust", "Main.rs"],
      'scheme': ["", "; ", "", '(define (main args) (print "Hello Scheme") 0)', "scheme", "Main.scm"],
      'commonlisp': ["", "; ", "", '(format t "Hello Common Lisp~%")', "lisp", "Main.lisp"],
      'mysql': ["create table Test(id integer, title varchar(100));\ninsert into Test(id, title) values(1, \"Hello\");\nselect * from Test;\n", "-- ", "", "", "sql", "Main.sql"],
      'nadesiko': ["", "# ", "", '「こんにちは」と表示。', "text", "Main.nako3"],
      'default': ["", "# ", "", "", "text", "Main.txt"]
    };
    languages = [
      {
        id: "swift",
        label: "Swift"
      }, {
        id: "c",
        label: 'C'
      }, {
        id: "cpp",
        label: 'C++'
      }, {
        id: "objective-c",
        label: 'Objective-C'
      }, {
        id: "java",
        label: "Java"
      }, {
        id: "php",
        label: "PHP"
      }, {
        id: "ruby",
        label: "Ruby"
      }, {
        id: "python",
        label: "Python2"
      }, {
        id: "python3",
        label: "Python3"
      }, {
        id: "perl",
        label: "Perl"
      }, {
        id: "kotlin",
        label: "Kotlin"
      }, {
        id: "scala",
        label: "Scala"
      }, {
        id: "go",
        label: "Go"
      }, {
        id: "csharp",
        label: "C#"
      }, {
        id: "haskell",
        label: "Haskell"
      }, {
        id: "clojure",
        label: "Clojure"
      }, {
        id: "d",
        label: "D"
      }, {
        id: "erlang",
        label: "Erlang"
      }, {
        id: "r",
        label: "R"
      }, {
        id: "javascript",
        label: "JavaScript"
      }, {
        id: "coffeescript",
        label: "CoffeeScript"
      }, {
        id: "typescript",
        label: "TypeScript"
      }, {
        id: "cobol",
        label: "Cobol"
      }, {
        id: "vb",
        label: "VB"
      }, {
        id: "fsharp",
        label: "F#"
      }, {
        id: "bash",
        label: "Bash"
      }, {
        id: "elixir",
        label: "Elixir"
      }, {
        id: "rust",
        label: "Rust"
      }, {
        id: "scheme",
        label: "Scheme"
      }, {
        id: "nadesiko",
        label: "Nadesiko"
      }, {
        id: "mysql",
        label: "MySQL"
      }
    ];
    languageId2LavelMap = {};
    for (i = 0, len = languages.length; i < len; i++) {
      language = languages[i];
      languageId2LavelMap[language.id] = language.label;
    }
    Language = {
      langinfos: langinfos,
      getTemplate: function(language, comments) {
        var comment, j, langinfo, len1, template;
        langinfo = langinfos[language];
        template = langinfo[0];
        for (j = 0, len1 = comments.length; j < len1; j++) {
          comment = comments[j];
          template += langinfo[1] + comment + "\n";
        }
        template += langinfo[2] + "\n";
        template += langinfo[3];
        return template;
      },
      getMainFilename: function(language) {
        var langinfo;
        langinfo = langinfos[language];
        return langinfo[5];
      },
      getPrefixTemplate: function(language) {
        var langinfo;
        langinfo = langinfos[language];
        return langinfo[0];
      },
      getACEmode: function(language) {
        var langinfo;
        langinfo = langinfos[language];
        return langinfo && langinfo[4];
      },
      getLanguages: function() {
        return languages;
      },
      getLabel: function(language) {
        var label;
        label = languageId2LavelMap[language];
        return label;
      },
      getTitle: function(language) {
        var label, title;
        label = languageId2LavelMap[language];
        if (!label) {
          return label;
        }
        if (language === 'python3') {
          label = 'Python';
        }
        title = label + ' Online';
        if (['java', 'c', 'cpp'].indexOf(language) >= 0) {
          title = 'Online ' + label + ' compiler';
        }
        if (language === 'php') {
          title = 'Online PHP Editor';
        }
        return title;
      }
    };
    return Language;
  });

}).call(this);
(function() {
  var app, demo_codes, hello_msg;

  app = angular.module("CodeApp");

  hello_msg = "Hello paiza.IO!";

  demo_codes = {
    'c': ["#include <stdio.h>\nint main(void){\n", "    // ", "    ", "}\n", "c_cpp", "Main.c", "printf(\"" + hello_msg + "\\n\");\nreturn 0;"],
    'cpp': ["#include <iostream>\nusing namespace std;\nint main(void){\n", "    // ", "    ", "}\n", "c_cpp", "Main.cpp", "cout << \"" + hello_msg + "\" << endl;"],
    'objective-c': ["#import <Foundation/Foundation.h>\nint main(void){\n    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];\n", "    // ", "    ", "    NSString *s = @\"XXXXXXXX\";\n    [pool release];\n    return 0;\n}", "objectivec", "Main.m", "[[NSFileHandle fileHandleWithStandardOutput] writeData: [s dataUsingEncoding: NSUTF8StringEncoding]];"],
    'java': ["import java.util.*\n\npublic class Main {\n    public static void main(String[] args) throws Exception {\n", "        // ", "    }\n}\n", "java", "Main.java", "System.out.println(\"" + hello_msg + "\")"],
    'kotlin': ["fun main(args: Array<String>) {\n", "    // ", "    ", "}\n", "kotlin", "Main.kt", "println(\"" + hello_msg + "\")"],
    'scala': ["object Main extends App{\n", "    // ", "    ", "}\n", "scala", "Main.scala", "println(\"" + hello_msg + "\")"],
    'csharp': ["public class Hello{\n    public static void Main(){\n", "        // ", "        ", "    }\n}\n", "csharp", "Main.cs", "System.Console.WriteLine(\"" + hello_msg + "\");"],
    'fsharp': ["", "// ", "", "", "text", "Main.fs", "printfn \"" + hello_msg + "\""],
    'go': ["package main\nimport \"fmt\"\nfunc main(){\n", "    // ", "    ", "}\n", "golang", "Main.go", "fmt.Println(\"" + hello_msg + "\")"],
    'haskell': ["", "-- ", "", "", "haskell", "Main.hs", "main = putStrLn \"" + hello_msg + "\""],
    'clojure': ["", "; ", "", "", "clojure", "Main.clj", "(println \"" + hello_msg + "\")"],
    'd': ["", "// ", "", "", "d", "Main.d", "import std.stdio;\nvoid main(){\n  writeln(\"" + hello_msg + "\");\n}"],
    'erlang': ["-module(main).\n-export([main/1]).\nmain([_]) ->\n", "%% ", "    ", "init:stop() .\n", "text", "main.erl", "io:format(\"" + hello_msg + "\"),\n"],
    'cobol': ["IDENTIFICATION DIVISION.\nprogram-id. Hello.\nprocedure division.\n", "# ", "", "", "cobol", "Main.cob", "display \"" + hello_msg + "\".\n"],
    'vb': ["public class compiler\n  shared function Main as integer\n", "' ", "    ", "    return 0\n  End function\nend class\n", "vbscript", "Main.vb", "Console.WriteLine (\"" + hello_msg + "\")"],
    'perl': ["", "# ", "", "", "perl", "Main.pl", "print \"" + hello_msg + "\\n\""],
    'python': ["# coding: utf-8\n", "# ", "", "", "python", "Main.py", "print \"" + hello_msg + "\\n\""],
    'python3': ["# coding: utf-8\n", "# ", "", "", "python", "Main.py", "print \"" + hello_msg + "\\n\""],
    'ruby': ["", "# ", "", "", "ruby", "Main.rb", "print \"" + hello_msg + "\\n\""],
    'php': ["<?php\n", "// ", "", "?>\n", "php", "Main.php", "print \"" + hello_msg + "\\n\""],
    'bash': ["", "# ", "", "", "sh", "Main.sh", "echo \"" + hello_msg + "\"\n"],
    'r': ["", "# ", "", "", "r", "Main.R", "cat(\"" + hello_msg + "\")\n"],
    'javascript': ["process.stdin.resume();\nprocess.stdin.setEncoding('utf8');\n", "// ", "", "", "javascript", "Main.js", "console.log(\"" + hello_msg + "\")"],
    'typescript': ["process.stdin.resume();\nprocess.stdin.setEncoding('utf8');\n", "// ", "", "", "javascript", "Main.js", "console.log(\"" + hello_msg + "\")"],
    'coffeescript': ["", "# ", "", "", "coffee", "Main.coffee", "console.log(\"" + hello_msg + "\")"],
    'nadesiko': ["", "# ", "", "", "text", "Main.nako3", "「" + hello_msg + "」と表示。"],
    'mysql': ["create table Test(id integer, title varchar(100));\ninsert into Test(id, title) values(1, \"Hello\");\n", "-- ", "", "", "sql", "Main.sql", "select \"" + hello_msg + "\" from Test;\n"]

    /*
        'default':[
        "",
        "# ",
        "",
        "",
        "text",
        "Main.txt",
        "",
      ],
     */
  };

  app.controller('AboutCtrl', function($scope, $timeout, Language, $routeParams, $rootScope) {
    var ace_editor, languageId, languages, longTitleBase, start_demo;
    ace_editor = null;
    $timeout(function() {
      var ref;
      return typeof twttr !== "undefined" && twttr !== null ? (ref = twttr.widgets) != null ? ref.load() : void 0 : void 0;
    }, 0, false);
    $timeout(function() {
      return FB.XFBML.parse(document.getElementById('fb-container'));
    }, 3000, false);
    languageId = $routeParams.language;
    languages = Language.getLanguages();
    $scope.languages = languages;
    $scope.languageId = languageId;
    $scope.languageLabel = Language.getLabel(languageId);
    if ($scope.languageLabel === 'Python3') {
      $scope.languageLabel = 'Python';
    }
    $scope.languageTitle = $rootScope.title = $rootScope.languageTitle = Language.getTitle(languageId);
    $rootScope.languageLabel = $scope.languageLabel;
    $rootScope.languageId = $scope.languageId;
    $scope.getLanguageTitle = Language.getTitle;
    if ($scope.languageLabel) {
      longTitleBase = $rootScope.title + " - ";
      if (["c", "cpp", "java"].indexOf(languageId) >= 0) {
        longTitleBase = "";
      }
      $rootScope.longTitle = longTitleBase + "Online " + $scope.languageLabel + " Compiler - Online " + $scope.languageLabel + " Editor - Run " + $scope.languageLabel + " Editor - Online " + $scope.languageLabel + " Runner";
      $rootScope.description = longTitleBase + "Online " + $scope.languageLabel + " Compiler - Online " + $scope.languageLabel + " Editor - Online " + $scope.languageLabel + " IDE - " + $scope.languageLabel + " Coding Online - Online " + $scope.languageLabel + " Runner - Share Save " + $scope.languageLabel + " Program online";
    }
    $scope.aceOptions = {
      theme: 'twilight',
      onLoad: function(_ace) {
        var ace_commands, param, session;
        if (_ace.loaded) {
          return;
        }
        _ace.loaded = true;
        ace_editor = _ace;
        param = {
          name: "submit",
          bindKey: {
            win: "Ctrl-Enter",
            mac: "Ctrl-Enter|Cmd-Enter"
          },
          exec: function(editor) {
            return $scope.submit();
          }
        };
        ace_commands = _ace.commands;
        ace_commands.addCommand(param);
        session = _ace.getSession();
        start_demo();
        return null;
      }
    };
    return start_demo = function() {
      var code_pos, language, update_code;
      languages = Object.keys(demo_codes);
      language = languages[Math.floor(Math.random() * languages.length)];
      $scope.source_code = "";
      $scope.language_label = Language.getLabel(language);
      $scope.language_state = false;
      $scope.language_cursor = true;
      code_pos = 0;
      $timeout(function() {
        $scope.language_state = true;
        $scope.language_cursor = false;
        $scope.aceOptions.mode = demo_codes[language][4];
        $scope.source_code = demo_codes[language][0] + demo_codes[language][2] + "\n" + demo_codes[language][3];
        $timeout(function() {
          ace_editor.gotoLine((demo_codes[language][0] + demo_codes[language][2]).split("\n").length, 1000);
          return update_code();
        }, 1000);
        return null;
      }, 1000);
      return update_code = function() {
        ace_editor.insert(demo_codes[language][6][code_pos]);
        code_pos += 1;
        if (code_pos < demo_codes[language][6].length) {
          $timeout(update_code, 100);
          return null;
        } else {
          $scope.submit_cursor = true;
          return $timeout(function() {
            $scope.submit_state = true;
            return $timeout(function() {
              $scope.submit_state = false;
              $scope.submit_cursor = false;
              $scope.show_output = true;
              return $timeout(function() {
                $scope.show_output = false;
                return start_demo();
              }, 2000);
            }, 500);
          }, 1000);
        }
      };
    };
  });

}).call(this);
(function() {
  jQuery(function() {
    $("a[rel~=popover], .has-popover").popover();
    return $("a[rel~=tooltip], .has-tooltip").tooltip();
  });

}).call(this);
(function() {
  var module;

  module = angular.module("comments", ["ngResource"]);

  module.factory("Comment", function($resource, $http) {
    var Comments;
    return Comments = $resource("/api/projects/:project_uid/comments/:id.json", {
      project_uid: "@project_uid",
      id: "@id"
    }, {
      update: {
        method: "PATCH"
      }
    });
  });

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.controller('CsrfCtrl', function($cookieStore) {
    var ele;
    ele = angular.element(document.getElementById("csrf")).attr("data-csrf");
    return $cookieStore.put("XSRF-TOKEN", ele);
  });

}).call(this);
(function() {
  var favoriteModule, root;

  root = typeof global !== "undefined" && global !== null ? global : window;

  favoriteModule = angular.module("favorites", ["ngResource"]);

  favoriteModule.factory("Favorite", [
    '$resource', '$http', function($resource, $http) {
      var Favorite;
      Favorite = $resource("/api/favorites/:id.json", {
        id: "@id"
      });
      return Favorite;
    }
  ]);

  root.angular = angular;

}).call(this);
(function() {
  var featuredProjectModule;

  featuredProjectModule = angular.module("featuredProjects", ["ngResource"]);

  featuredProjectModule.factory("FeaturedProject", [
    '$resource', function($resource) {
      var FeaturedProject;
      return FeaturedProject = $resource("/api/featured_projects/:id.json", {
        id: "@id"
      });
    }
  ]);

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.directive("featuredProjectsSection", function(Project, Language) {
    return {
      restrict: "EA",
      templateUrl: '/assets/projects/_featured_projects_section-4d0c8b58dcaf1ba734fe5d499663df83.html',
      scope: {},
      link: function($scope, element, attrs) {
        $scope.projects = [];
        Project.query({
          limit: 9,
          only_featured: true
        }, function(result) {
          var i, len, project, projects;
          projects = result.projects;
          for (i = 0, len = projects.length; i < len; i++) {
            project = projects[i];
            project.mode = Language.getACEmode(project.language);
          }
          return $scope.projects = projects;
        }, function(error) {
          return show_error(error);
        });
        return null;
      }
    };
  });

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.controller('FeedbackIndexCtrl', function($scope, $http, $location) {
    $scope.types = ["Question", "Bug", "Request", "Press", "Others"];
    $scope.feedback = {};
    $scope.feedback.type = "";
    return $scope.submit = function() {
      return $http.post('/api/feedback/sendmail.json', $scope.feedback).success(function(data, status, headers, config) {
        return $location.path("/feedback/sent");
      }).error(function(data, status, headers, config) {
        return alert("failed: " + data);
      });
    };
  });

}).call(this);
(function() {
  var gistModule;

  gistModule = angular.module("gists", ["ngResource"]);

  gistModule.factory("Gist", function($resource, $http, Language) {
    var Gist, api_endpoint, getConfig, get_github_provider, get_github_username, gist2project, languageGist2Project;
    languageGist2Project = function(gistLanguage) {
      var gist2project_map;
      gist2project_map = {
        'C': 'c',
        'C#': 'csharp',
        'C++': 'cpp',
        'CoffeeScript': 'coffeescript',
        'Erlang': 'erlang',
        'Haskell': 'haskell',
        'Clojure': 'clojure',
        'D': 'd',
        'Java': 'java',
        'JavaScript': 'javascript',
        'Objective-C': 'objective-c',
        'Perl': 'perl',
        'PHP': 'php',
        'Python': 'python',
        'Ruby': 'ruby',
        'SQL': 'mysql',
        'F#': 'fsharp',
        'Shell': 'bash',
        'Go': 'go',
        'COBOL': 'cobol',
        'Visual Basic': 'visual basic',
        'R': 'r'
      };
      return gist2project_map[gistLanguage];
    };
    api_endpoint = "https://api.github.com/";
    get_github_provider = function() {
      var github_provider, providers;
      if (!current_user) {
        return null;
      }
      providers = current_user.providers;
      github_provider = providers.filter(function(provider) {
        return provider.provider === "github";
      })[0];
      return github_provider;
    };
    getConfig = function() {
      var github_provider, token;
      github_provider = get_github_provider();
      if (github_provider === null) {
        return;
      }
      token = github_provider.token;
      return {
        headers: {
          Authorization: "token " + token
        }
      };
    };
    get_github_username = function() {
      var github_provider;
      github_provider = get_github_provider();
      if (github_provider) {
        return github_provider.name;
      } else {
        return null;
      }
    };
    gist2project = function(gist, success, error) {
      var file, file_, filename, filename_, project, ref;
      project = {};
      project.gist_id = gist.id;
      project.source_files = [];
      filename = null;
      file = null;
      ref = gist.files;
      for (filename_ in ref) {
        file_ = ref[filename_];
        filename = filename_;
        file = file_;
      }
      project.language = Gist.languageGist2Project(file.language);
      project.mode = Language.getACEmode(project.language);
      if (file.content) {
        project.source_files.push({
          filename: filename,
          body: file.content
        });
        return success(project);
      }

      /*
      else
        $http.get(gist.raw_url).success( (body)->
          project.source_files.push({
            filename: filename,
            body: body
          })
          project.linenum = result.split("\n").length
          success(project)
        ).error(error)
       */
    };
    Gist = {
      get_github_provider: get_github_provider,
      languageGist2Project: languageGist2Project,
      query: function(parameters, success, error) {
        return $http.get(api_endpoint + "gists", getConfig()).then(success, error);
      },
      get: function(parameters, success, error) {
        return $http.get(api_endpoint + "gists/" + parameters.id, getConfig()).then(success, error);
      },
      get_as_project: function(parameters, success, error) {
        return Gist.get(parameters, function(result) {
          return gist2project(result.data, success, error);
        });
      },
      save: function(parameters, postData, success, error) {
        return $http.post(api_endpoint + "gists", postData, getConfig()).then(success, error);
      },
      update: function(parameters, postData, success, error) {
        return $http.patch(api_endpoint + "gists/" + parameters.id, postData, getConfig()).then(success, error);
      },
      "delete": function(parameters, postData, success, error) {
        return $http["delete"](api_endpoint + "gists/" + parameters.id, getConfig()).then(success, error);
      }
    };
    return Gist;
  });

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.controller('HelpCtrl', function($scope, $http) {
    return $http({
      method: 'GET',
      format: 'json',
      url: '/api/runners/api_get_versions'
    }).success(function(data, status, headers, config) {
      return $scope.versions = angular.fromJson(data);
    }).error(function(data, status, headers, config) {
      return $scope.versions = [
        {
          name: '-',
          version: 'Load failed...',
          memory_limit: '-'
        }
      ];
    });
  });

}).call(this);
(function() {
  angular.module('i18nfilter', ['i18nmessages']).filter('i18n', function(i18nmessages) {
    return function(input) {
      return i18nmessages[input] || '?' + input + '?';
    };
  });

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.controller('NoViewCtrl', function($rootScope, $location) {
    var un;
    $rootScope.noview = true;
    return un = $rootScope.$on('$locationChangeSuccess', function() {
      $rootScope.noview = false;
      un();
      return null;
    });
  });

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.directive("projectComments", function(Comment) {
    return {
      restrict: "EA",
      templateUrl: '/assets/projects/_comments-a3be0fedc05d2f9280ebd3d3024704f6.html',
      scope: {
        comments: '=comments',
        projectUid: '=projectUid',
        current_user: '=currentUser'
      },
      link: function($scope, element, attrs) {
        var project_uid;
        project_uid = $scope.projectUid;
        Comment.query({
          project_uid: project_uid
        }, function(comments) {
          return Array.prototype.push.apply($scope.comments, comments);
        }, function(error) {
          return show_error(error);
        });
        $scope.addComment = function(comment_message) {
          var comment;
          $scope.commentPromise = comment = Comment.save({
            project_uid: project_uid
          }, {
            comment: {
              message: comment_message
            }
          });
          $scope.comments.push(comment);
          return $scope.comment_message = '';
        };
        $scope.deleteComment = function(delete_id) {
          var newcomments;
          $scope.commentPromise = Comment["delete"]({
            project_uid: project_uid,
            id: delete_id
          });
          newcomments = $scope.comments.filter(function(comment) {
            return comment.id !== delete_id;
          });
          $scope.comments.splice(0, $scope.comments.length);
          Array.prototype.push.apply($scope.comments, newcomments);
          return true;
        };
        return $scope.updateComment = function(comment) {
          return $scope.commentPromise = Comment.update({
            project_uid: project_uid,
            id: comment.id
          }, {
            comment: comment
          });
        };
      }
    };
  });

}).call(this);
(function() {
  var projectModule;

  projectModule = angular.module("projects", ["ngResource"]);

  projectModule.factory("Project", function($resource, $http) {
    var Project;
    Project = $resource("/api/projects/:uid.json", {
      uid: "@uid"
    }, {
      query: {
        method: "GET",
        isArray: false
      },
      update: {
        method: "PATCH"
      },
      run: {
        url: "/api/projects/:uid/run",
        method: "POST",
        isArray: false
      }
    });
    angular.extend(Project, {
      get_gist_project: function(project) {
        var external_projects, gist_project;
        external_projects = project.external_projects;
        gist_project = external_projects != null ? external_projects.filter(function(external_project) {
          return external_project.service === "gist";
        })[0] : void 0;
        return gist_project;
      },
      get_gist_id: function(project) {
        var gist_project;
        gist_project = Project.get_gist_project(project);
        return gist_project != null ? gist_project.external_id : void 0;
      },
      diff_source_files: function(src_source_files, dst_source_files) {
        var deleted_files, updated_files;
        updated_files = dst_source_files.filter(function(dst_source_file) {
          var src_source_file;
          src_source_file = dst_source_file.id && src_source_files.filter(function(s) {
            return s.id === dst_source_file.id;
          })[0];
          if (src_source_file && dst_source_file.filename === src_source_file.filename && dst_source_file.body === src_source_file.body && dst_source_file.position === src_source_file.position) {
            return false;
          } else {
            return true;
          }
        });
        deleted_files = src_source_files.filter(function(src_source_file) {
          return !dst_source_files.filter(function(dst_source_file) {
            return dst_source_file.id === src_source_file.id;
          })[0];
        });
        return {
          updated: updated_files,
          deleted: deleted_files
        };
      }
    });
    return Project;
  });

}).call(this);
(function() {
  var ProjectsCreateOrShowCtrl, aceframe_content_resize, amznKeywordTimer, app, showAmazonAd, timerAdArea, update_id;

  app = angular.module("CodeApp");

  update_id = null;

  window.TogetherJSConfig_on_ready = function() {
    update_id = Math.floor(Math.random() * 100000000);
    return setTimeout(function() {
      return TogetherJS.send({
        type: "update_request",
        update_id: update_id
      });
    }, 3000);
  };

  aceframe_content_resize = function() {
    var aceframe, aceframe_content, aceframe_footer, aceframe_header, h;
    aceframe = angular.element('.aceframe');
    aceframe_header = angular.element('.aceframe-header');
    aceframe_content = angular.element('.aceframe-content');
    aceframe_footer = angular.element('.aceframe-footer');
    h = aceframe.height() - aceframe_header.height() - aceframe_footer.height();
    aceframe_content.height(h);
    return window.aceeditor.resize();
  };

  amznKeywordTimer = null;

  timerAdArea = null;

  showAmazonAd = function($sce, $scope, languageLabel, app_locale) {
    var amazonAdHtml, amzn_assoc_default_search_key, intervalCounter, marketplace, timezoneOffset;
    return;
    if (window.amzn_assoc_ad_div_adunit_count === void 0) {
      window.amzn_assoc_ad_div_adunit_count = 0;
    }
    $("#amzn_assoc_ad_div_adunit_" + (window.amzn_assoc_ad_div_adunit_count - 1)).remove();
    amzn_assoc_default_search_key = languageLabel;
    if (amzn_assoc_default_search_key === 'C++') {
      amzn_assoc_default_search_key = 'C';
    }
    window.amzn_assoc_ad_type = "responsive_search_widget";
    window.amzn_assoc_tracking_id = "paiza-io-22";
    window.amzn_assoc_marketplace = "amazon";
    window.amzn_assoc_region = "JP";
    window.amzn_assoc_placement = "";
    window.amzn_assoc_search_type = "search_widget";
    "search_box";
    window.amzn_assoc_width = "250";
    "160";
    window.amzn_assoc_height = "3000";
    "600";
    window.amzn_assoc_default_search_category = "Books";
    window.amzn_assoc_default_search_key = amzn_assoc_default_search_key;
    window.amzn_assoc_theme = "light";
    window.amzn_assoc_bg_color = "FFFFFF";
    marketplace = "JP";
    timezoneOffset = (new Date()).getTimezoneOffset();
    if (timezoneOffset === -540) {

    } else {
      window.amzn_assoc_tracking_id = "paizaio-20";
      window.amzn_assoc_region = "US";
      marketplace = "US";
    }
    amazonAdHtml = '<script src="//z-fe.amazon-adsystem.com/widgets/q?ServiceVersion=20070822&Operation=GetScript&ID=OneJS&WS=1&Marketplace=' + marketplace + '&rand=' + Math.floor(Math.random() * 10000000) + '"></script>';
    $scope.amazonAdHtmlBind = $sce.trustAsHtml(amazonAdHtml);
    intervalCounter = 0;
    return timerAdArea = setInterval(function() {
      var amzn_assoc_ad_div_adunit_element, mouseHovering;
      intervalCounter += 1;
      if (intervalCounter > 100) {
        clearInterval(timerAdArea);
      }
      amzn_assoc_ad_div_adunit_element = $("#amzn_assoc_ad_div_adunit_" + window.amzn_assoc_ad_div_adunit_count);
      if (amzn_assoc_ad_div_adunit_element[0]) {
        clearInterval(timerAdArea);
        $(".amazon-ad-area").append(amzn_assoc_ad_div_adunit_element[0]);
        amzn_assoc_ad_div_adunit_element.show();
        window.amzn_assoc_ad_div_adunit_count += 1;
        clearInterval(amznKeywordTimer);
        mouseHovering = false;
        amzn_assoc_ad_div_adunit_element[0].addEventListener("mouseenter", function() {
          return mouseHovering = true;
        });
        amzn_assoc_ad_div_adunit_element[0].addEventListener("mouseleave", function() {
          return mouseHovering = false;
        });
        return amznKeywordTimer = setInterval(function() {
          var activeElement, activeElementFocusCounter, activeElementFocusTimer, amznIframe, category, item, items, keyword, message, rand;
          if (mouseHovering) {
            return;
          }
          items = [["イヤホン", "All"], ["イヤホン", "All"], ["Mac", "PCHardware"], ["MacBook", "PCHardware"], ["椅子", "All"], ["ChromeBook", "All"], ["ゲーミングチェア", "All"], ["ゲーミングデスク", "All"], ["スピーカー", "All"], ["プロジェクトマネジメント", "Books"], ["アルゴリズム", "Books"], ["クラウド", "Books"], ["競技プログラミング", "Books"], ["機械学習", "Books"], ["統計", "Books"], ["英語", "Books"], ["CPU", "Books"], ["Unity", "Books"], ["Docker", "Books"], ["Linux", "Books"], ["AWS", "Books"], ["Web", "Books"], ["HTML", "Books"], ["Go", "Books"], ["Python", "Books"], ["SQL", "Books"], ["React", "Books"], ["Vue.js", "Books"], ["正規表現", "Books"], ["ハッカー", "Books"], ["オブジェクト指向", "Books"], ["アジャイル", "Books"], ["スクラム", "Books"], ["マイクロサービス", "Books"], ["プログラミングコンテスト", "Books"], ["プロジェクトマネジメント", "Books"], ["進撃の巨人", "Books"], ["エヴァンゲリオン", "All"], ["アンチウィルス", "Software"], ["セキュリティ", "Software"], ["セキュリティ", "Books"], ["Yogibo", "All"], ["リモートワーク", "All"], ["プログラミング", "Books"], ["ゲーム", "VideoGames"], ["PlayStation", "All"], ["Nintendo Switch", "All"], ["Android", "All"], ["iPhone", "All"], ["iPad", "All"], ["モバイルバッテリー", "All"], ["ポータブルHDD", "All"], ["4K モニター", "All"], ["モニター", "PCHardware"], ["キーボード", "PCHardware"], ["キーボード", "HHKB"], ["マウス", "PCHardware"], ["整腸剤", "All"], ["整腸剤", "All"], ["目薬", "All"], ["ラジコン", "Toys"], ["ドローン", "Toys"], ["apex legends", "All"], ["メモリカード", "All"], ["ピアノ", "All"], ["Web", "All"], ["アニメ", "All"], ["目の疲れ", "All"], ["ブルーベリー", "All"], ["サプリメント", "All"], ["ガジェット", "All"], ["充電器", "All"], ["モバイルバッテリー", "All"]];
          rand = Math.random();
          if (rand < 0.3 || marketplace !== "JP") {
            item = [languageLabel, "Books"];
          } else {
            item = items[Math.floor(Math.random() * items.length)];
          }
          keyword = item[0];
          category = item[1];
          amznIframe = amzn_assoc_ad_div_adunit_element.find("iframe");
          message = '{"operation": "selectSuggestion", "text": "' + keyword + '", "catValue": "' + category + '", "catHTML": "' + category + '", "catSearch": "' + category + '", "clicked": true}';
          activeElement = document.activeElement;
          amznIframe[0].contentWindow.postMessage(message, "*");
          activeElementFocusCounter = 0;
          return activeElementFocusTimer = setInterval(function() {
            activeElementFocusCounter += 1;
            if (activeElementFocusCounter >= 10) {
              clearInterval(activeElementFocusTimer);
            }
            return activeElement.focus();
          }, 100);
        }, 30000);
      }
    }, 100);
  };

  ProjectsCreateOrShowCtrl = function($sce, $scope, $rootScope, $window, $cookieStore, $timeout, $route, $location, $filter, $routeParams, $uibModal, storage, Language, Project, Favorite, FeaturedProject, Gist) {
    var Autocomplete, confirm_message, flag_ws_onmessage, is_dirty, language_tools, leave_confirm, live_end, live_send_update, live_start, myDoLiveAutocomplete, output_type_to_url_name, params, project_language_changing, split_pane_element, template_code, togetherjs_update, togetherjs_updating, updateAceOptions, updateTemplate, util, ws;
    $scope.ctrl = $scope;
    $scope.comments = [];
    $rootScope.spa = true;
    $scope.current_user = current_user;
    $scope.progress_transition = true;
    $scope.running = false;
    $scope.bar_show = false;
    $scope.dynamic = 80;
    $scope.bar_message = '';
    $scope.type = 'success';
    $scope.project.language = $routeParams.language || $cookieStore.get('language') || 'php';
    $scope.project.network = true;
    $scope.project.share = 'private';
    $scope.project.output_type = null;
    $scope.saved_source_files = [];
    $scope.languages = Language.getLanguages();
    $scope.fullscreen = true;
    if (!window.isMobile) {
      $scope.showAmazonAd = true;
    }
    $scope.$watch('project.language', function(post, pre) {
      var timezoneOffset;
      $rootScope.languageId = $scope.project.language;
      $rootScope.languageLabel = Language.getLabel($rootScope.languageId);
      if ($rootScope.languageLabel === 'Python3') {
        $rootScope.languageLabel = 'Python';
      }
      $rootScope.title = $rootScope.languageTitle = Language.getTitle($rootScope.languageId);
      $timeout(function() {
        return showAmazonAd($sce, $scope, $rootScope.languageLabel, $rootScope.app_locale);
      }, 1000);
      timezoneOffset = (new Date()).getTimezoneOffset();
      if (timezoneOffset === -540) {
        $scope.amznTextLinkUrl = 'https://www.amazon.co.jp/gp/search?ie=UTF8&tag=paiza-io-22&linkCode=ur2&linkId=f562664023798b86044a18006819f32b&camp=247&creative=1211&index=books&keywords=' + encodeURIComponent($rootScope.languageLabel);
      } else {
        $scope.amznTextLinkUrl = 'https://www.amazon.com/gp/search?ie=UTF8&tag=paizaio-20&linkCode=ur2&linkId=17627e718f204c292aad58dff993ea1a&camp=1789&creative=9325&index=books&keywords=' + encodeURIComponent($rootScope.languageLabel);
      }
      return $scope.amznTextLinkOnClick = function() {
        return $window.ga('send', {
          hitType: 'event',
          eventCategory: 'affiliate',
          eventAction: 'click',
          eventLabel: $rootScope.languageId,
          eventValue: 1
        });
      };
    });

    /*
    disqus_reset_itr = ()->
      DISQUS.reset({
          reload: true,
          config: ()->
              this.page.identifier = 'projects-' + $scope.project.uid
               * this.page.url = $location.absUrl()
               * this.page.url = $location.absUrl()
      })
      delete window.disqus_ready
      disqus_update_count()
    
    disqus_update_count = ()->
      $.getScript("http://" + disqus_shortname + ".disqus.com/count-data.js?1=projects-" + $scope.project.uid + "&date=" + (new Date()));
    
    window.disqus_onNewComment = ()->
      disqus_update_count()
    
    $scope.disqus_reset = ()->
      if DISQUS?
          disqus_reset_itr()
      else
          window.disqus_ready = disqus_reset_itr
     */
    $scope.editor_scrollPageUp = function() {
      return window.aceeditor.scrollPageUp();
    };
    $scope.editor_scrollPageDown = function() {
      return window.aceeditor.scrollPageDown();
    };
    $scope.isMobileSafari = isMobileSafari();
    $scope.get_embed_url = function(embed_theme) {
      var ref;
      return location.protocol + "//" + location.host + "/projects/e/" + $scope.project.uid + "?theme=" + ((ref = $scope.aceEditorConfig.embedTheme) != null ? ref : 'twilight');
    };
    $scope.get_project_url = function() {
      return location.protocol + "//" + location.host + "/projects/" + $scope.project.uid;
    };
    $scope.embedModal = function() {
      var modal;
      modal = $uibModal.open({
        templateUrl: '/assets/projects/modal_embed-1f38c80b313d7f63def52f9366c04f89.html',
        scope: $scope
      });
      return modal.opened.then(function() {
        return $timeout(function() {
          var ref;
          if (typeof twttr !== "undefined" && twttr !== null) {
            if ((ref = twttr.widgets) != null) {
              ref.load();
            }
          }
          return FB.XFBML.parse(document.getElementById('fb-container'));
        }, 0, false);
      });
    };
    if ($location.path().match(/^\/projects\/e\//)) {
      $rootScope.embed = true;
      $scope.embed = true;
      $scope.fullscreen = true;
    }
    if ($rootScope.app_locale === "ja-jp" && !$scope.embed) {
      $scope.advertisement = true;
    } else {
      $scope.advertisement = false;
    }
    $scope.advertisement = true;
    params = $route.current.params;
    if (params['embed']) {
      $timeout(function() {
        $scope.embed = true;
        return $scope.fullscreen = true;
      }, 0);
    }
    leave_confirm = null;
    is_dirty = null;
    if (!$scope.embed) {
      confirm_message = $filter('i18n')('confirm_leave');
      leave_confirm = function() {
        return confirm(confirm_message);
      };
      is_dirty = function() {
        var diff;
        if (!$scope.project.source_files) {
          return false;
        }
        if (template_code) {
          if ($scope.project.source_files.length === 1) {
            if (template_code === $scope.project.source_files[0].body) {
              return false;
            }
          }
        }
        diff = Project.diff_source_files($scope.saved_source_files, $scope.project.source_files);
        if (diff.updated.length === 0 && diff.deleted.length === 0) {
          return false;
        } else {
          return true;
        }
      };
      $scope.$on('$locationChangeStart', function(event) {
        var ret;
        if (is_dirty()) {
          console.log('$locationChangeStart:' + event);
          ret = leave_confirm();
          if (!ret) {
            return event.preventDefault();
          }
        }
      });
      $scope.$on('$locationChangeSuccess', function(event) {
        return window.onbeforeunload = null;
      });
      window.onbeforeunload = function(event) {
        if (is_dirty()) {
          if (typeof event === 'undefined') {
            event = window.event;
          }
          if (event) {
            event.returnValue = confirm_message;
          }
          return confirm_message;
        }
      };
    }
    togetherjs_updating = false;
    togetherjs_update = function(do_reinitialize, func) {
      if (!TogetherJS.running) {
        return;
      }
      if (togetherjs_updating) {
        return;
      }
      togetherjs_updating = true;
      TogetherJS._configuration["ignoreForms"] = ["#form_editor"];
      func();
      togetherjs_updating = false;
      if (do_reinitialize) {
        $timeout(function() {
          TogetherJS._configuration["ignoreForms"] = [];
          return TogetherJS.reinitialize();
        }, 1000, false);
        $timeout(function() {
          return TogetherJS.reinitialize();
        }, 0, false);
      }
      return true;
    };
    $scope.output_type_options = [
      {
        name: 'Text',
        value: null
      }, {
        name: 'HTML',
        value: 'html'
      }, {
        name: 'JSON',
        value: 'json'
      }
    ];
    $scope.schedule_options = [
      {
        name: 'No scheduling',
        value: null
      }, {
        name: 'Every hour',
        value: '1h'
      }, {
        name: 'Every day',
        value: '1d'
      }
    ];
    output_type_to_url_name = function(output_type) {
      if (output_type === null) {
        return "txt";
      } else {
        return output_type;
      }
    };
    $scope.get_output_url = function(project) {
      if (!project.uid || !project.stdout) {
        return null;
      }
      return ($location.protocol()) + "://out." + ($location.host()) + ":" + ($location.port()) + "/projects/" + project.uid + "/output/output." + (output_type_to_url_name(project.output_type));
    };
    $scope.current_language_label = function() {
      return Language.getLabel($scope.project.language);
    };
    $scope.aceEditorKeymaps = ["normal", "vim", "emacs"];
    $scope.aceEditorThemes = [
      {
        key: "chrome",
        name: "Chrome",
        shade: "Bright"
      }, {
        key: "clouds",
        name: "Clouds",
        shade: "Bright"
      }, {
        key: "crimson_editor",
        name: "Crimson Editor",
        shade: "Bright"
      }, {
        key: "dawn",
        name: "Dawn",
        shade: "Bright"
      }, {
        key: "dreamweaver",
        name: "Dreamweaver",
        shade: "Bright"
      }, {
        key: "eclipse",
        name: "Eclipse",
        shade: "Bright"
      }, {
        key: "katzenmilch",
        name: "KatzenMilch",
        shade: "Bright"
      }, {
        key: "kuroir",
        name: "Kuroir",
        shade: "Bright"
      }, {
        key: "github",
        name: "GitHub",
        shade: "Bright"
      }, {
        key: "solarized_light",
        name: "Solarized Light",
        shade: "Bright"
      }, {
        key: "textmate",
        name: "TextMate",
        shade: "Bright"
      }, {
        key: "tomorrow",
        name: "Tomorrow",
        shade: "Bright"
      }, {
        key: "xcode",
        name: "XCode",
        shade: "Bright"
      }, {
        key: "ambiance",
        name: "Ambiance",
        shade: "Dark"
      }, {
        key: "chaos",
        name: "Chaos",
        shade: "Dark"
      }, {
        key: "clouds_midnight",
        name: "Clouds Midnight",
        shade: "Dark"
      }, {
        key: "cobalt",
        name: "Cobalt",
        shade: "Dark"
      }, {
        key: "idle_fingers",
        name: "idle_fingers",
        shade: "Dark"
      }, {
        key: "kr",
        name: "kr",
        shade: "Dark"
      }, {
        key: "kr_theme",
        name: "krTheme",
        shade: "Dark"
      }, {
        key: "merbivore",
        name: "Merbivore",
        shade: "Dark"
      }, {
        key: "merbivore_soft",
        name: "Merbivore Soft",
        shade: "Dark"
      }, {
        key: "mono_industrial",
        name: "Mono Industrial",
        shade: "Dark"
      }, {
        key: "monokai",
        name: "Monokai",
        shade: "Dark"
      }, {
        key: "pastel_on_dark",
        name: "Pastel on Dark",
        shade: "Dark"
      }, {
        key: "solarized_dark",
        name: "Solarized Dark",
        shade: "Dark"
      }, {
        key: "terminal",
        name: "Terminal",
        shade: "Dark"
      }, {
        key: "tomorrow_night",
        name: "Tomorrow Night",
        shade: "Dark"
      }, {
        key: "tomorrow_night_blue",
        name: "Tomorrow Night Blue",
        shade: "Dark"
      }, {
        key: "tomorrow_night_bright",
        name: "Tomorrow Night Bright",
        shade: "Dark"
      }, {
        key: "tomorrow_night_eighties",
        name: "Tomorrow Night 80s",
        shade: "Dark"
      }, {
        key: "twilight",
        name: "Twilight",
        shade: "Dark"
      }, {
        key: "vibrant_ink",
        name: "Vibrant Ink",
        shade: "Dark"
      }
    ];
    $scope.aceEditorFontSizes = ["10px", "11px", "12px", "13px", "14px", "16px", "18px", "20px", "24px", "48px"];
    storage.bind($scope, 'aceEditorConfig', {
      defaultValue: {
        theme: null,
        embedTheme: null,
        keyboardHandler: "normal",
        tabSize: 4,
        autoCompletion: true,
        showGutter: true,
        showInvisibles: false,
        fontSize: "12px"
      }
    });
    Autocomplete = window.ace.require('ace/autocomplete').Autocomplete;
    util = window.ace.require('ace/autocomplete/util');
    language_tools = window.ace.require('ace/ext/language_tools');
    language_tools.setCompleters([language_tools.textCompleter, language_tools.keyWordCompleter, language_tools.snippetCompleter]);
    myDoLiveAutocomplete = function(e) {
      var editor, hasCompleter, prefix;
      editor = e.editor;
      hasCompleter = editor.completer && editor.completer.activated;
      if (e.command.name === 'backspace') {
        if (hasCompleter && !util.getCompletionPrefix(editor)) {
          editor.completer.detach();
        }
      } else if (e.command.name === 'insertstring') {
        prefix = util.getCompletionPrefix(editor);
        if (prefix && !hasCompleter) {
          if (!editor.completer) {
            editor.completer = new Autocomplete;
          }
          editor.completer.autoInsert = false;
          editor.completer.autoSelect = false;
          editor.completer.exactMatch = true;
          editor.completer.showPopup(editor);
        }
      }
    };
    updateAceOptions = function() {
      var keyboardHandler, ref, ref1, ref2;
      window.aceeditor.setOptions({
        enableBasicAutocompletion: $scope.aceEditorConfig.autoCompletion,
        enableSnippets: $scope.aceEditorConfig.autoCompletion
      });
      window.aceeditor.getSession().setTabSize($scope.aceEditorConfig.tabSize);
      keyboardHandler = $scope.aceEditorConfig.keyboardHandler;
      if (keyboardHandler === "normal") {
        keyboardHandler = null;
      } else {
        keyboardHandler = "ace/keyboard/" + keyboardHandler;
      }
      console.log(window.aceeditor.getKeyboardHandler());
      window.aceeditor.setKeyboardHandler(keyboardHandler);
      window.aceeditor.setFontSize((ref = $scope.aceEditorConfig.fontSize) != null ? ref : "12px");
      $scope.aceOptions.theme = (ref1 = (ref2 = $routeParams.theme) != null ? ref2 : $scope.aceEditorConfig.theme) != null ? ref1 : 'twilight';
      $scope.aceOptions.showGutter = $scope.aceEditorConfig.showGutter;
      $scope.aceOptions.showInvisibles = $scope.aceEditorConfig.showInvisibles;
      return $cookieStore.put("aceEditorConfig", $scope.aceEditorConfig);
    };
    $scope.renaming_keyup = function(scope, $event) {
      if ($event.keyCode === 13) {
        if ($event) {
          $event.stopPropagation();
          $event.preventDefault();
        }
        if (event) {
          event.stopPropagation();
          event.preventDefault();
        }
        return scope.renaming = false;
      }
    };
    $scope["delete"] = function() {
      if (confirm("Are you sure to delete project ?")) {
        return Project["delete"]({
          uid: $scope.project.uid
        }, function() {
          return $timeout(function() {
            return $location.path("/");
          }, 1000);
        }, function(error) {
          return show_error(error);
        });
      }
    };
    $scope.submit_clicked_default = function() {
      return $scope.submit_clicked(true, true, $scope.project.id && !$scope.project.is_owner);
    };
    $scope.submit_clicked = function(flag_save, flag_run, flag_fork) {
      return $scope.submit(flag_save, flag_run, flag_fork);
    };
    $scope.$watch("project.favorite", function(post, pre) {
      var param;
      console.log("project.favorite fired");
      if (pre === post) {
        return;
      }
      if (!$scope.ready) {
        return;
      }
      if (post === true && (typeof current_user === "undefined" || current_user === null)) {
        alert($filter('i18n')('ask_sign_in'));
        $scope.project.favorite = false;
        return;
      }
      if (post === true && (!$scope.project || !$scope.project.id)) {
        alert("Please run the code once to favorite.");
        $scope.project.favorite = false;
        return;
      }
      param = {
        project_id: $scope.project.id
      };
      if ($scope.project.favorite) {
        return Favorite.save(param);
      } else {
        return Favorite["delete"](param);
      }
    });
    $scope.$watch("project.featured", function(post, pre) {
      var ref;
      if (pre === post) {
        return;
      }
      if (!$scope.ready) {
        return;
      }
      if (typeof current_user === "undefined" || current_user === null) {
        alert($filter('i18n')('ask_sign_in'));
        $scope.project.featured = false;
      }
      if (!((ref = $scope.project) != null ? ref.id : void 0)) {
        alert("Please run the code once to favorite.");
        $scope.project.featured = false;
      }
      if ($scope.project.featured) {
        return FeaturedProject.save({
          project_id: $scope.project.id
        }, function(result) {
          return null;
        }, function(error) {
          return show_error(error);
        });
      } else {
        return FeaturedProject["delete"]({
          project_id: $scope.project.id
        });
      }
    });
    $scope.$watch("link_gist", function(post, pre) {
      if (pre === post) {
        return;
      }
      if (!$scope.ready) {
        return;
      }
      if (post === true && !Gist.get_github_provider()) {
        alert($filter('i18n')('ask_sign_in_github'));
        $scope.link_gist = false;
        return;
      }
      if (post === true && !$scope.project.is_owner) {
        alert($filter('i18n')('not_owner'));
        $scope.link_gist = false;
      }
    });
    $scope.$watch("project.share", function(post, pre) {
      console.log("share is " + $scope.project.share);
      if (pre === post) {
        return;
      }
      if (!$scope.project.id) {
        return;
      }
      if (!$scope.ready) {
        return;
      }
      if ($scope.embed) {
        return;
      }
      return Project.update({
        uid: $scope.project.uid
      }, {
        share: $scope.project.share
      }, function(result) {
        return $scope.project.share = result.share;
      }, function(error) {
        return show_error(error);
      });
    });
    $scope.$watch("project.output_type", function(post, pre) {
      console.log("output_type is " + $scope.project.output_type);
      if (pre === post) {
        return;
      }
      if (!$scope.project.id) {
        return;
      }
      if (!$scope.ready) {
        return;
      }
      if ($scope.embed) {
        return;
      }
      return Project.update({
        uid: $scope.project.uid
      }, {
        output_type: $scope.project.output_type || null
      }, function(result) {
        return $scope.project.output_type = result.output_type;
      }, function(error) {
        return show_error(error);
      });
    });
    $scope.$watch("project.schedule", function(post, pre) {
      console.log("schedule is " + $scope.project.schedule);
      if (pre === post) {
        return;
      }
      if (!$scope.project.id) {
        return;
      }
      if (!$scope.ready) {
        return;
      }
      return Project.update({
        uid: $scope.project.uid
      }, {
        schedule: $scope.project.schedule
      }, function(result) {
        return $scope.project.schedule = result.schedule;
      }, function(error) {
        return show_error(error);
      });
    });

    /*
    $scope.$watch("project.live", (post, pre)->
      console.log("project.live fired")
      if pre == post
        return
      if !$scope.project.id
        return
      if ! $scope.ready
        return
      Project.update({uid: $scope.project.uid}, {live: $scope.project.live}, (result)->
        $scope.project.live = result.live
        if $scope.project.live
          live_start()
        else
          live_send_update()
          live_end()
      )
    )
     */
    if ($scope.fullscreen) {
      $timeout(function() {
        return aceframe_content_resize();
      }, 100);
      $timeout(function() {
        return aceframe_content_resize();
      }, 1000);
    }
    angular.element($window).bind('resize', function() {
      if ($scope.fullscreen) {
        return aceframe_content_resize();
      }
    });
    split_pane_element = angular.element('div.split-pane');
    split_pane_element.on('resize', function() {
      return aceframe_content_resize();
    });
    split_pane_element.splitPane();
    $scope.$watch("progress_transition", function(post, pre) {
      if (pre === post) {
        return;
      }
      return aceframe_content_resize();
    });

    /*
    document.addEventListener("fullscreenchange", ()->
      $scope.fullscreen = document.fullscreen
      $scope.$apply()
    , false)
    document.addEventListener("mozfullscreenchange", ()->
      $scope.fullscreen = document.mozFullScreen
      $scope.$apply()
    , false)
    document.addEventListener("webkitfullscreenchange", ()->
      $scope.fullscreen = document.webkitIsFullScreen
      $scope.$apply()
    , false);
    document.addEventListener("msfullscreenchange", ()->
      $scope.fullscreen = document.msFullscreenElement
      $scope.$apply()
    ,false
    )
     */
    $scope.$watch("aceEditorConfig", function(post, pre) {
      if (pre === post) {
        return;
      }
      return updateAceOptions();
    }, true);
    ws = null;
    flag_ws_onmessage = false;
    $scope.live_start = live_start = function() {
      if (ws) {
        return;
      }
      flag_ws_onmessage = false;
      ws = new WebSocket("wss://ws.paiza.io:8080/");
      ws.onopen = function(e) {
        console.log("opened");
        return ws.send(JSON.stringify({
          id: $scope.project.id || "top",
          command: "subscribe"
        }));
      };
      ws.onmessage = function(e) {
        var data, json;
        console.log("message:", e);
        flag_ws_onmessage = true;
        data = e.data;
        json = JSON.parse(data);
        if (json.command === "update") {
          if (json.source_files != null) {
            $scope.project.source_files = json.source_files;
          }
          if (json.live != null) {
            $scope.project.live = json.live;
          }
          if (json.network != null) {
            $scope.project.network = json.network;
          }
          return $scope.$$phase || $scope.$apply();
        } else if (json.command === "reload") {
          togetherjs_update(true, function() {
            return $route.reload();
          });
          return flag_ws_onmessage = false;
        }
      };
      ws.onclose = function(e) {
        console.log("WebSocket Closed. code=" + e.code + ", type=" + e.type);
        return live_end();
      };
      return $scope.$on('$destroy', function() {
        return live_end();
      });
    };
    live_send_update = function() {
      if (!ws) {
        return;
      }
      if (ws.readyState !== 1) {
        return;
      }
      if (flag_ws_onmessage) {
        return;
      }
      return ws.send(JSON.stringify({
        id: $scope.project.id || "top",
        command: "update",
        source_files: $scope.project.source_files,
        live: $scope.project.live,
        network: $scope.project.network
      }));
    };
    live_end = function() {
      if (ws) {
        ws.close();
        return ws = null;
      }
    };
    TogetherJS.hub.on("reload", function(msg) {
      if (!msg.sameUrl) {
        return;
      }
      return togetherjs_update(false, function() {
        return $route.reload();
      });
    });
    TogetherJS.hub.on("update", function(msg) {
      if (!msg.sameUrl) {
        return;
      }
      if (msg.update_id) {
        if (msg.update_id !== update_id) {
          return;
        }
        update_id = null;
      }
      if (msg.project) {
        return togetherjs_update(true, function() {
          var key;
          for (key in msg.project) {
            $scope.project[key] = msg.project[key];
          }
          return $scope.$apply();
        });
      }
    });
    TogetherJS.hub.on("update_request", function(msg) {
      if (!msg.sameUrl) {
        return;
      }
      return TogetherJS.send({
        type: "update",
        update_id: msg.update_id,
        project: {
          source_file_pos: $scope.project.source_file_pos,
          source_files: $scope.project.source_files,
          input: $scope.project.input
        }
      });
    });
    $scope.$watch("project.source_file_pos", function(post, pre) {
      if (pre === post) {
        return;
      }
      if ($scope.project.source_file_pos !== null && $scope.project.source_file_pos !== void 0) {
        return togetherjs_update(true, function() {
          return TogetherJS.send({
            type: "update",
            project: {
              source_file_pos: $scope.project.source_file_pos,
              source_files: $scope.project.source_files
            }
          });
        });
      }
    });
    $scope.$watch("project.source_files", function(post, pre) {
      return live_send_update();
    }, true);
    $scope.$watch("project.network", function(post, pre) {
      return live_send_update();
    }, true);
    $scope.$watch("fullscreen", function(post, pre) {
      var aceframe_content;
      if (pre === post) {
        return;
      }
      if ($scope.fullscreen) {

        /*
        element = document.getElementsByClassName("aceframe")[0]
        if ! $scope.embed
          if element.webkitRequestFullScreen
            if(/Chrome/.test(navigator.userAgent))
              element.webkitRequestFullScreen(Element.ALLOW_KEYBOARD_INPUT)
          else if element.mozRequestFullScreen
            element.mozRequestFullScreen()
          else if element.requestFullScreen
            element.requestFullScreen()
         */
        $timeout(function() {
          return aceframe_content_resize();
        }, 100);
      } else {

        /*
        if ! $scope.embed
          if document.webkitCancelFullScreen
            document.webkitCancelFullScreen()
          else if document.mozCancelFullScreen
            document.mozCancelFullScreen()
          else if document.exitFullscreen
            document.exitFullscreen()
         */
        aceframe_content = angular.element('.aceframe-content');
        aceframe_content.height('auto');
      }
    });
    template_code = null;
    updateTemplate = function() {
      var comments, main_filename;
      $scope.aceOptions.mode = Language.getACEmode($scope.project.language);
      comments = ["Your code here!"];
      if (!$scope.project.language) {
        return;
      }
      template_code = Language.getTemplate($scope.project.language, comments);
      main_filename = Language.getMainFilename($scope.project.language);
      $scope.project.source_files = [
        {
          filename: main_filename,
          body: template_code
        }
      ];
      $scope.project.source_file_pos = 0;
      $timeout(function() {
        var prefixTemplate;
        prefixTemplate = Language.getPrefixTemplate($scope.project.language);
        window.aceeditor.gotoLine(prefixTemplate.split("\n").length + comments.length, 1000);
        if (!isMobileSafari()) {
          return window.aceeditor.focus();
        }
      }, 0, false);
    };
    $scope.updateAnnotations = function() {
      $timeout(function() {
        var annotations, count, remove_watch;
        annotations = $scope.project.source_files[$scope.project.source_file_pos].annotations || [];
        window.aceeditor.getSession().setAnnotations(annotations);
        count = 0;
        remove_watch = $scope.$watch("project.source_files", function(oldval, newval) {
          console.log("watch callback...", oldval, newval, count);
          if (oldval === newval) {
            return;
          }
          window.aceeditor.getSession().setAnnotations([]);
          return remove_watch();
        }, true);
      }, 0, false);
    };
    $scope.update_result_tab = function() {
      var ref;
      $rootScope.title = ($scope.project.title ? $scope.project.title : '') + '(' + $scope.current_language_label() + ')';
      $scope.type = (ref = $scope.project.exit_code === 0) != null ? ref : {
        'success': 'error'
      };
      $scope.progress_transition = false;
      $scope.dynamic = 100;
      if ($scope.project.build_exit_code !== null && $scope.project.build_exit_code !== 0) {
        $scope.type = 'danger';
        $scope.bar_message = 'Compile error';
        return $scope.result_tab_active = 'tab_build_output_active';
      } else if ($scope.project.result === "timeout") {
        $scope.type = 'warning';
        $scope.bar_message = 'Timeout';
        if ($scope.project.stderr && $scope.project.stderr !== '') {
          return $scope.result_tab_active = 'tab_stderr_active';
        } else {
          return $scope.result_tab_active = 'tab_stdout_active';
        }
      } else if ($scope.project.exit_code !== null && $scope.project.exit_code !== 0) {
        $scope.type = 'warning';
        $scope.bar_message = 'Runtime error(Exit status:' + $scope.project.exit_code;
        if ($scope.project.exit_code > 128) {
          $scope.bar_message += '(' + window.signame($scope.project.exit_code - 128) + ')';
        }
        $scope.bar_message += ')';
        if ($scope.project.stderr && $scope.project.stderr !== "") {
          return $scope.result_tab_active = 'tab_stderr_active';
        } else if ($scope.project.stdout !== null) {
          return $scope.result_tab_active = 'tab_stdout_active';
        }
      } else if ($scope.project.stdout !== null) {
        $scope.type = 'success';
        $scope.bar_message = 'Success';
        if ($scope.project.stderr) {
          $scope.result_tab_active = 'tab_stderr_active';
        } else {
          $scope.result_tab_active = 'tab_stdout_active';
        }
        return $timeout(function() {
          var ref1;
          if (typeof twttr !== "undefined" && twttr !== null) {
            if ((ref1 = twttr.widgets) != null) {
              ref1.load();
            }
          }
          return FB.XFBML.parse(document.getElementById('fb-container'));

          /*
          $('#fb-container')[0].addEventListener('click', (e) ->
            e.preventDefault();
            e.stopPropagation();
            fbLink = $location.absUrl()
            fbDescription =  "Here is my #{$rootScope.languageLabel} code (#{$scope.project.source_files[0].body.split('\n').length} lines) on online editor/compiler! ";
            FB.ui(
              {
                 * method: 'feed',
                method: 'share',
                 * name: 'Online editor and compiler - paiza.IO',
                 * link: fbLink,
                href: fbLink,
                 * picture: 'https://paiza.io/assets/movie_title-1a9f7f2c8bf2d59dafed5ac01d7c8eab.png',
                 * caption: 'Caption like which appear as title of the dialog box',
                 * description: fbDescription,
                 * message: 'hoge',
              }
            )
          , true)
           */
        }, 0, false);
      } else {
        return $scope.result_tab_active = 'tab_stdin_active';
      }
    };
    $scope.aceOptions = {
      theme: $scope.aceEditorConfig.theme,
      onLoad: function(_ace) {
        var ace_commands, iOSDoubleQuoteCommand1, iOSDoubleQuoteCommand2, iOSQuoteCommand1, iOSQuoteCommand2, session, submit_command, yen_command;
        if ($scope.aceOnLoadDone) {
          return;
        }
        $scope.aceOnLoadDone = true;
        window.aceeditor = _ace;
        updateAceOptions();
        submit_command = {
          name: "submit",
          bindKey: {
            win: "Ctrl-Enter",
            mac: "Ctrl-Enter|Cmd-Enter"
          },
          exec: function(editor) {
            return $scope.submit_clicked_default();
          }
        };
        yen_command = {
          name: "yen",
          bindKey: {
            win: "¥",
            mac: "¥"
          },
          exec: function(editor) {
            return _ace.insert("\\");
          }
        };
        ace_commands = _ace.commands;
        ace_commands.addCommand(submit_command);
        ace_commands.addCommand(yen_command);
        iOSQuoteCommand1 = {
          name: "iOSQuote1",
          bindKey: {
            win: "’",
            mac: "’"
          },
          exec: function(editor) {
            return _ace.insert("'");
          }
        };
        ace_commands.addCommand(iOSQuoteCommand1);
        iOSQuoteCommand2 = {
          name: "iOSQuote2",
          bindKey: {
            win: "‘",
            mac: "‘"
          },
          exec: function(editor) {
            return _ace.insert("'");
          }
        };
        ace_commands.addCommand(iOSQuoteCommand2);
        iOSDoubleQuoteCommand1 = {
          name: "iOSDoubleQuote1",
          bindKey: {
            win: "”",
            mac: "”"
          },
          exec: function(editor) {
            return _ace.insert('"');
          }
        };
        ace_commands.addCommand(iOSDoubleQuoteCommand1);
        iOSDoubleQuoteCommand2 = {
          name: "iOSDoubleQuote2",
          bindKey: {
            win: "“",
            mac: "“"
          },
          exec: function(editor) {
            return _ace.insert('"');
          }
        };
        ace_commands.addCommand(iOSDoubleQuoteCommand2);
        if ($scope.aceEditorConfig.autoCompletion) {
          ace_commands.on('afterExec', myDoLiveAutocomplete);
        }
        session = _ace.getSession();
        return _ace.on("paste", function(e) {
          var newText, text;
          text = e.text;
          newText = text.replace(/\r\n/g, '\n');
          return e.text = newText;
        });
      }
    };
    project_language_changing = false;
    $scope.$watch("project.language", function(post, pre) {
      var ret;
      console.log("project.language changed. pre=" + pre + ", post=" + post);
      if (pre === post) {
        return;
      }
      if (!$scope.ready) {
        return;
      }
      if (project_language_changing === true) {
        project_language_changing = false;
        return;
      }
      if (pre !== post) {
        if (is_dirty()) {
          ret = leave_confirm();
          if (!ret) {
            project_language_changing = true;
            $scope.project.language = pre;
            return;
          }
        }
      }
      if (window.aceeditor) {
        updateTemplate();
        return $cookieStore.put('language', $scope.project.language);
      }
    });
    if ($scope.ready && !$scope.project.source_files) {
      updateTemplate();
    }
    if ($scope.project.language) {
      $scope.aceOptions.mode = Language.getACEmode($scope.project.language);
    }
    $scope.new_source_file = function() {
      $scope.project.source_files.push({
        filename: "File" + $scope.project.source_files.length,
        body: ""
      });
      if (TogetherJS.running) {
        togetherjs_update(true, function() {
          return TogetherJS.send({
            type: "update",
            project: {
              source_files: $scope.project.source_files
            }
          });
        });
      }
      return true;
    };
    $scope.delete_source_file = function(pos) {
      $scope.project.source_files.splice(pos, 1);
      togetherjs_update(true, function() {
        return TogetherJS.send({
          type: "update",
          project: {
            source_files: $scope.project.source_files
          }
        });
      });
      return true;
    };
    $scope.submit = function(flag_save, flag_run, flag_fork) {
      var delete_files_param, diff, file, gist_files_param, gist_post_data, gist_save, i, id_params, j, k, l, len, len1, len2, len3, m, post_data, ref, ref1, ref2, ref3, save, source_file, source_files, source_files_diff, update_external_project;
      $scope.progress_transition = false;
      $timeout(function() {
        $scope.dynamic = 0;
        return $timeout(function() {
          $scope.progress_transition = true;
          return $timeout(function() {
            console.log("timeout after submit");
            return $scope.dynamic = 90;
          });
        });
      });
      $scope.bar_message = '';
      $scope.running = true;
      $scope.bar_show = flag_run;
      $scope.type = null;
      ref = $scope.project.source_files;
      for (i = j = 0, len = ref.length; j < len; i = ++j) {
        source_file = ref[i];
        source_file.position = i;
      }
      diff = Project.diff_source_files($scope.saved_source_files, $scope.project.source_files);
      delete_files_param = diff.deleted.map(function(deleted_file) {
        return {
          id: deleted_file.id,
          _destroy: true
        };
      });
      source_files_diff = diff.updated.concat(delete_files_param);
      post_data = {
        'project': {
          'id': $scope.project.id,
          'source_files': source_files_diff,
          'language': $scope.project.language,
          'input': $scope.project.input,
          'share': $scope.project.share,
          'network': $scope.project.network,
          'live': !flag_fork && $scope.project.live,
          'external_projects': $scope.external_projects,
          'output_type': $scope.project.output_type,
          'schedule': $scope.project.schedule,
          'title': $scope.project.title
        },
        'run': flag_run,
        'save': flag_save
      };
      if (flag_fork) {
        $scope.gist_id = null;
        $scope.link_gist = false;
        $scope.link_gist_synced = false;
        post_data['project']['id'] = null;
        source_files = $scope.project.source_files.map(function(file) {
          return {
            filename: file.filename,
            body: file.body
          };
        });
        post_data['project']['source_files'] = source_files;
        post_data['project']['parent_id'] = $scope.project.id;
        post_data['fork'] = true;
      }
      console.log("post_data=", post_data);
      update_external_project = function() {
        var external_projects;
        if ($scope.project.id && $scope.gist_id && !Project.get_gist_id($scope.project)) {
          external_projects = [
            {
              provider: "github",
              service: "gist",
              external_id: $scope.gist_id
            }
          ];
          return Project.update({
            uid: $scope.project.uid
          }, {
            project: {
              external_projects: external_projects
            }
          }, function(result) {
            $scope.project.external_projects = result.external_projects;
            return console.log("Updated external_projects:" + result);
          }, function(error) {
            console.log("Failed to update gist:" + error);
            return alert("Failed to update gist:" + error);
          });
        }
      };
      if ($scope.link_gist) {
        gist_files_param = {};
        if (flag_fork || !$scope.link_gist_synced) {
          ref1 = $scope.project.source_files;
          for (k = 0, len1 = ref1.length; k < len1; k++) {
            file = ref1[k];
            gist_files_param[file.filename] = {
              content: file.body
            };
          }
        } else {
          ref2 = diff.updated;
          for (l = 0, len2 = ref2.length; l < len2; l++) {
            file = ref2[l];
            gist_files_param[file.filename] = {
              content: file.body
            };
          }
          ref3 = diff.deleted;
          for (m = 0, len3 = ref3.length; m < len3; m++) {
            file = ref3[m];
            gist_files_param[file.filename] = null;
          }
        }
        gist_post_data = {
          "public": $scope.project.share === "public",
          files: gist_files_param
        };
        gist_save = null;
        if ($scope.gist_id) {
          gist_save = Gist.update;
        } else {
          gist_save = Gist.save;
        }
        $scope.link_gist_synced = false;
        gist_save({
          id: $scope.gist_id
        }, gist_post_data, function(result) {
          $scope.gist_id = result.data.id;
          $scope.link_gist_synced = true;
          update_external_project();
          return console.log("Saved:", result);
        }, function(error) {
          return console.log("Failed:", error);
        });
      } else if (!flag_save) {
        $scope.project.external_project = null;
      }
      if ($scope.project.id && !flag_fork) {
        save = Project.update;
        id_params = {
          uid: $scope.project.uid
        };
      } else {
        save = Project.save;
        id_params = {};
      }
      $scope.ready = false;
      return save(id_params, post_data, function(result) {
        var key, key2, lastRoute, len4, len5, n, need_update_all_sourcefiles, o, ref4, ref5, un;
        if (result.uid !== $scope.project.uid) {
          lastRoute = $route.current;
          un = $rootScope.$on('$locationChangeSuccess', function() {
            $route.current = lastRoute;
            un();
            return null;
          });
          $location.path("/projects/" + ($scope.embed ? 'e/' : '') + result.uid);
          console.log("result=", result);
        }
        $timeout(function() {
          $scope.ready = true;
          if (TogetherJS.running) {
            return TogetherJS.reinitialize();
          }
        }, 0, false);
        need_update_all_sourcefiles = false;
        ref4 = $scope.project.source_files;
        for (i = n = 0, len4 = ref4.length; n < len4; i = ++n) {
          source_file = ref4[i];
          for (key in source_file) {
            if (key !== 'body' && key !== 'filename') {
              delete source_file[key];
            }
          }
        }
        for (key in result) {
          if (key === 'source_files') {
            ref5 = result.source_files;
            for (i = o = 0, len5 = ref5.length; o < len5; i = ++o) {
              source_file = ref5[i];
              if (i >= $scope.project.source_files.length || $scope.project.source_files[i].filename !== source_file.filename || $scope.project.source_files[i].body !== source_file.body) {
                need_update_all_sourcefiles = true;
                break;
              }
              for (key2 in source_file) {
                $scope.project.source_files[i][key2] = source_file[key2];
              }
            }
          } else if (key === 'source_file_pos') {

          } else {
            $scope.project[key] = result[key];
          }
        }
        if (need_update_all_sourcefiles) {
          $scope.project.source_files = result.source_files;
          $scope.project.source_file_pos = 0;
        }
        if ($scope.project.source_file_pos >= $scope.project.source_file_pos.length) {
          $scope.project.source_file_pos = 0;
        }
        $scope.project.source_files[$scope.project.source_file_pos].active = true;
        if (flag_save) {
          $scope.saved_source_files = JSON.parse(JSON.stringify($scope.project.source_files));
        }
        $scope.update_result_tab();
        $scope.running = false;
        update_external_project();
        $scope.updateAnnotations();
        togetherjs_update(true, function() {
          return TogetherJS.send({
            type: "reload"
          });
        });
        if (ws) {
          return ws.send(JSON.stringify({
            id: $scope.project.id || "top",
            command: "reload"
          }));
        }
      }, function(error) {
        $scope.ready = true;
        $scope.running = false;
        $scope.progress_transition = false;
        $scope.dynamic = 100;
        $scope.type = 'danger';
        return $scope.bar_message = error.data;
      });
    };
    return true;
  };

  app.controller('ProjectsIndexCtrl', function($scope, $http, $location, $filter, $routeParams, Language, Project, Favorite, FeaturedProject, Gist) {
    var gistRunQuery;
    console.log("Start: ProjectsIndexCtrl");
    $scope.ctrl = $scope;
    if ($location.path().match(/^\/projects\/?(.*)/)) {
      $scope.who = RegExp.$1;
      if ($scope.who === "") {
        $scope.who = 'me';
      }
    }
    $scope.get_github_provider = function() {
      return Gist.get_github_provider();
    };
    if ($scope.who === "gists" && !$scope.get_github_provider()) {
      alert($filter('i18n')('ask_sign_in_github'));
      $location.path("/projects/featured");
      return;
    }
    if ($scope.who !== 'all' && $scope.who !== 'featured' && current_user === null) {
      if ($scope.who !== 'me') {
        alert($filter('i18n')('ask_sign_in'));
      }
      $location.path("/projects/featured");
      return;
    }
    $scope.who_tab_selected = function(who_id) {
      return $scope.who = who_id;
    };
    $scope.current_user = current_user;
    gistRunQuery = function(offset, limit, language) {
      return Gist.query({}, function(results) {
        var busy_count, file, filename, fn, i, j, len, project, projects, ref, ref1, result;
        $scope.paging.count = results.data.length;
        projects = [];
        busy_count = 0;
        i = 0;
        if (results.length === 0) {
          $scope.paging.busy = false;
        }
        ref = results.data;
        fn = function(project) {
          busy_count += 1;
          return $http.get(project.raw_url).success(function(result) {
            project.source_files[0].body = result;
            project.linenum = result.split("\n").length;
            busy_count -= 1;
            if (busy_count === 0) {
              return $scope.paging.busy = false;
            }
          }).error(function(error) {
            return show_error(error);
          });
        };
        for (j = 0, len = ref.length; j < len; j++) {
          result = ref[j];
          result = results.data[i++];
          project = {};
          project.gist_id = result.id;
          project.source_files = [];
          ref1 = result.files;
          for (filename in ref1) {
            file = ref1[filename];
            project.source_files.push({
              filename: filename,
              body: "Loading " + file.raw_url + "..."
            });
            project.linenum = 1;
            project.language = Gist.languageGist2Project(file.language);
            project.mode = Language.getACEmode(project.language);
            project.raw_url = file.raw_url;
            break;
          }
          if (!project.raw_url) {
            continue;
          }
          if (language && project.language !== language) {
            continue;
          }
          if (i < offset || i >= offset + limit) {
            continue;
          }
          projects.push(project);
          fn(project);
        }
        if (offset === 0) {
          $scope.projects = [];
        }
        $scope.projects = $scope.projects.concat(projects);
        return null;
      });
    };
    $scope.runQuery = function(init, offset, limit) {
      var params;
      if ($scope.paging.busy) {
        return;
      }
      if (!init && $scope.paging.count === $scope.projects.length) {
        return;
      }
      $scope.paging.busy = true;
      offset = offset || 0;
      limit = limit || 10;
      if ($scope.who === "gists") {
        gistRunQuery(offset, limit);
        return;
      }
      params = {
        offset: offset,
        limit: limit,
        language: $scope.language,
        only_me: $scope.who === 'me' || $scope.who === 'favorites',
        only_favorite: $scope.who === 'favorites',
        only_featured: $scope.who === 'featured',
        search_text: $scope.search_text
      };
      console.log("querying...");
      return Project.query(params, function(result) {
        var count, j, len, main_source_code, project, projects;
        projects = result.projects;
        count = result.count;
        for (j = 0, len = projects.length; j < len; j++) {
          project = projects[j];
          project.mode = Language.getACEmode(project.language);
          if (project.source_files.length > 0) {
            main_source_code = project.source_files[0].body;
          } else {
            main_source_code = "";
          }
          project.linenum = count_linenum(main_source_code);
        }
        if (offset) {
          $scope.projects = $scope.projects.concat(projects);
        } else {
          $scope.projects = projects;
        }
        $scope.paging.count = count;
        return $scope.paging.busy = false;
      });
    };
    return $scope.destroy = function() {
      var original;
      if (confirm("Are you sure?")) {
        original = this.projects;
        return this.project.destroy(function() {
          return $scope.posts = _.without($scope.posts, original);
        });
      }
    };
  });

  app.controller('ProjectsCreateCtrl', function($sce, $scope, $rootScope, $window, $cookieStore, $timeout, $route, $location, $filter, $routeParams, $uibModal, storage, Language, Project, Favorite, FeaturedProject, Gist) {
    var main_filename;
    $scope.project = {};
    $scope.result_tab_active = 'tab_stdin_active';
    if ($routeParams.language && $routeParams.source_code) {
      $scope.project.language = $routeParams.language;
      $scope.project.input = $routeParams.input;
      main_filename = Language.getMainFilename($scope.project.language);
      $scope.project.source_files = [
        {
          filename: main_filename,
          body: $routeParams.source_code
        }
      ];
      $scope.project.source_file_pos = 0;
      $scope.saved_source_files = JSON.parse(JSON.stringify($scope.project.source_files));
    }
    $scope.ready = true;
    return ProjectsCreateOrShowCtrl.apply(this, arguments);
  });

  app.controller('ProjectsShowCtrl', function($sce, $scope, $rootScope, $window, $cookieStore, $timeout, $route, $location, $filter, $routeParams, $uibModal, storage, Language, Project, Favorite, FeaturedProject, Gist) {
    var error, gist_id, success, uid;
    uid = $routeParams.uid;
    gist_id = $routeParams.gist_id;
    $scope.project = {};
    $scope.project.stdout = "Dummy";
    success = function(project) {
      if (project.error) {
        console.log(project.error);
        alert(project.error);
        $location.path("/");
        return;
      }
      $scope.project = project;
      if (uid) {
        $scope.saved_source_files = JSON.parse(JSON.stringify($scope.project.source_files));
        $scope.gist_id = Project.get_gist_id($scope.project);
        $scope.link_gist = !!$scope.gist_id;
        $scope.link_gist_synced = $scope.link_gist;
      } else {
        $scope.gist_id = gist_id;
        $scope.link_gist = true;
      }
      if ($scope.project.live) {
        $scope.live_start();
      }
      $scope.update_result_tab();
      if ($routeParams.tab === 'comments') {
        $scope.result_tab_active = 'tab_comment2_active';
      }
      $scope.aceOptions.mode = Language.getACEmode($scope.project.language);
      $scope.updateAnnotations();
      $timeout(function() {
        $scope.ready = true;
        if (TogetherJS.running) {
          return TogetherJS.reinitialize();
        }
      }, 0, false);
      return $timeout(function() {
        return aceframe_content_resize();
      }, 0, false);
    };
    error = function(error) {
      var ref;
      $location.path("/");
      return show_error("Cannot find the project with uid:" + uid + "\n(Error:" + (error != null ? (ref = error.data) != null ? ref.error : void 0 : void 0) + ")", function() {
        return true;
      });
    };
    if (uid) {
      Project.get({
        uid: uid
      }, success, error);
    } else {
      Gist.get_as_project({
        id: gist_id
      }, success, error);
    }
    return ProjectsCreateOrShowCtrl.apply(this, arguments);
  });

  app.directive("dropzone", function() {
    return {
      restrict: "A",
      link: function(scope, elem) {
        elem.bind('dragover', function(evt) {
          return false;
        });
        elem.bind('drop', function(evt) {
          var file, fn, j, len, reader, ref;
          evt.stopPropagation();
          evt.preventDefault();
          ref = evt.originalEvent.dataTransfer.files;
          fn = function(file) {
            return reader.onload = function(evt) {
              var body, source_file;
              body = evt.target.result;
              source_file = {
                filename: file.name,
                body: body
              };
              scope.project.source_files.push(source_file);
              scope.$apply();
              return null;
            };
          };
          for (j = 0, len = ref.length; j < len; j++) {
            file = ref[j];
            reader = new FileReader();
            fn(file);
            reader.readAsText(file);
          }
          return null;
        });
        return null;
      }
    };
  });

  app.directive("dropzoneInput", function() {
    return {
      restrict: "A",
      link: function(scope, elem) {
        elem.bind('dragover', function(evt) {
          return false;
        });
        elem.bind('drop', function(evt) {
          var file, reader;
          if (evt.originalEvent.dataTransfer.files) {
            evt.stopPropagation();
            evt.preventDefault();
            reader = new FileReader();
            reader.onload = function(evt) {
              scope.project.input = evt.target.result;
              scope.$apply();
              return null;
            };
            file = evt.originalEvent.dataTransfer.files[0];
            return reader.readAsText(file);
          }
        });
        return null;
      }
    };
  });

  window.projects_test = function() {
    return console.log("test");
  };

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.directive("projectsList", function(Language, $location, $routeParams) {
    return {
      restrict: "EA",
      templateUrl: '/assets/projects/_list-c0cc3013ee12e541d314205138138e49.html',
      link: function($scope, element, attrs) {
        $scope.languages = Language.getLanguages();
        $scope.getLanguageLabel = Language.getLabel;
        $scope.language = $routeParams.language || null;
        $scope.search = function() {
          return $scope.runQuery(true);
        };
        $scope.$watchGroup(["language"], function(pre, post) {
          $location.search("language", $scope.language);
          return $scope.runQuery(true);
        });
        $scope.paging = {};
        $scope.paging.busy = false;
        return $scope.paging.nextPage = function() {
          if ($scope.paging.busy) {
            return;
          }
          return $scope.runQuery(false, $scope.projects.length);
        };
      }
    };
  });

}).call(this);
(function() {
  var app;

  angular.module('fromNowFilter', []).filter('from_now', function() {
    return function(date) {
      return moment(date).fromNow();
    };
  });

  app = angular.module('CodeApp');

  app.run(function($rootScope) {
    console.log("running...");
    console.log("app_locale", app_locale);
    $rootScope.app_locale = window.app_locale;
    $rootScope.app_locale_short = window.app_locale_short;
    return moment.locale(window.app_locale);
  });

  app.run(function($location, $rootScope) {
    return $rootScope.$on('$routeChangeSuccess', function(event, current, previous) {
      return $rootScope.title = current.title;
    });
  });

  app.config(function($routeProvider, $httpProvider, $locationProvider) {
    var route;
    route = $routeProvider;
    route = route.when("/", {
      controller: 'AboutCtrl',
      templateUrl: '/assets/about-bf72ec1c68aafbfb88437a6ebe7b95c2.html'
    });
    ['', '/ja', '/en', '/es'].forEach(function(localePath) {
      if (localePath !== '') {
        route = route.when("" + localePath, {
          controller: 'AboutCtrl',
          templateUrl: '/assets/about-bf72ec1c68aafbfb88437a6ebe7b95c2.html'
        });
      }
      return route = route.when(localePath + "/languages/php", {
        redirectTo: localePath + "/languages/online-php-editor"
      }).when(localePath + "/languages/c", {
        redirectTo: localePath + "/languages/online-c-compiler"
      }).when(localePath + "/languages/cpp", {
        redirectTo: localePath + "/languages/online-cpp-compiler"
      }).when(localePath + "/languages/java", {
        redirectTo: localePath + "/languages/online-java-compiler"
      }).when(localePath + "/languages/online-:language-editor", {
        controller: 'AboutCtrl',
        templateUrl: '/assets/about-bf72ec1c68aafbfb88437a6ebe7b95c2.html'
      }).when(localePath + "/languages/online-:language-compiler", {
        controller: 'AboutCtrl',
        templateUrl: '/assets/about-bf72ec1c68aafbfb88437a6ebe7b95c2.html'
      }).when(localePath + "/languages/:language", {
        controller: 'AboutCtrl',
        templateUrl: '/assets/about-bf72ec1c68aafbfb88437a6ebe7b95c2.html'
      }).when(localePath + "/projects/new", {
        controller: 'ProjectsCreateCtrl',
        templateUrl: '/assets/projects/new-b6f3b8c71d554648cc355b463b4427c5.html'
      });
    });
    route = route.when("/help", {
      controller: 'HelpCtrl',
      templateUrl: '/assets/help-14cf6da2b24886cab322338b83c9cf20.html',
      title: 'Help'
    }).when("/terminal", {
      controller: 'TerminalCtrl',
      templateUrl: '/assets/terminal-e3680101d1fafa6d86af6e8153f31533.html'
    }).when("/feedback/index", {
      controller: 'FeedbackIndexCtrl',
      templateUrl: '/assets/feedback/index-a98780b0564f0946396e27c28173ac26.html'
    }).when("/feedback/sent", {
      templateUrl: '/assets/feedback/sent-a9015303cb8328005a1bd7a1084d72c4.html'
    }).when("/projects/new", {
      controller: 'ProjectsCreateCtrl',
      templateUrl: '/assets/projects/new-b6f3b8c71d554648cc355b463b4427c5.html'
    }).when("/projects", {
      controller: 'ProjectsIndexCtrl',
      templateUrl: '/assets/projects/index-26b51a0b59dfd717fcb0eb19fb742a1d.html'
    }).when("/projects/favorites", {
      controller: 'ProjectsIndexCtrl',
      templateUrl: '/assets/projects/index-26b51a0b59dfd717fcb0eb19fb742a1d.html'
    }).when("/projects/featured", {
      controller: 'ProjectsIndexCtrl',
      templateUrl: '/assets/projects/index-26b51a0b59dfd717fcb0eb19fb742a1d.html'
    }).when("/projects/all", {
      controller: 'ProjectsIndexCtrl',
      templateUrl: '/assets/projects/index-26b51a0b59dfd717fcb0eb19fb742a1d.html'
    }).when("/projects/gists", {
      controller: 'ProjectsIndexCtrl',
      templateUrl: '/assets/projects/index-26b51a0b59dfd717fcb0eb19fb742a1d.html'
    }).when("/projects/e/new", {
      controller: 'ProjectsCreateCtrl',
      templateUrl: '/assets/projects/show_embed-5159ee485ffeaebb3e38e0b9ff3c8130.html'
    }).when("/projects/new", {
      controller: 'ProjectsCreateCtrl',
      templateUrl: '/assets/projects/new-b6f3b8c71d554648cc355b463b4427c5.html'
    }).when("/projects/e/:uid", {
      controller: 'ProjectsShowCtrl',
      templateUrl: '/assets/projects/show_embed-5159ee485ffeaebb3e38e0b9ff3c8130.html'
    }).when("/projects/:uid", {
      controller: 'ProjectsShowCtrl',
      templateUrl: '/assets/projects/show-b6f3b8c71d554648cc355b463b4427c5.html'
    }).when("/gists/:gist_id", {
      controller: 'ProjectsShowCtrl',
      templateUrl: '/assets/projects/show-b6f3b8c71d554648cc355b463b4427c5.html'
    }).when("/users/show/:id", {
      controller: 'UsersShowCtrl',
      templateUrl: '/assets/users/show-2d9100ef077465b87b85fac9c18c4297.html'
    }).when("/users/show/:id/favorites", {
      controller: 'UsersShowCtrl',
      templateUrl: '/assets/users/show-2d9100ef077465b87b85fac9c18c4297.html'
    }).otherwise({
      controller: 'NoViewCtrl',
      template: "<!-- Route not found!-->"
    });
    $locationProvider.html5Mode(true);
    $httpProvider.defaults.headers.post['Accept'] = 'application/json';
    $httpProvider.defaults.headers.post['Content-Type'] = 'application/json; charset=utf-8';
    $httpProvider.defaults.headers.get = {};
    $httpProvider.defaults.headers.get['Accept'] = 'application/json';
    return $httpProvider.defaults.headers.get['Content-Type'] = 'application/json; charset=utf-8';
  });

  app.controller('NavController', function($scope, $location) {
    $scope.isActive = function(location) {
      return location === $location.path();
    };
    return $scope.isRoot = function() {
      return "/" === $location.path();
    };
  });

  app.directive('showFocus', function($timeout) {
    return function(scope, element, attrs) {
      return scope.$watch(attrs.showFocus, function(post, pre) {
        return $timeout(function() {
          if (post) {
            return element.focus();
          }
        }, false);
      });
    };
  });

}).call(this);
(function() {
  var runnersModule;

  runnersModule = angular.module("runners", ["ngResource"]);

  runnersModule.factory("Runner", function($http) {
    var Runner;
    Runner = {};
    Runner.api_create = function(runner) {
      var url;
      url = "/api/runners/api_create";
      return $http.post(url, runner);
    };
    Runner.api_get_details = function(id) {
      var url;
      url = "/api/runners/api_get_details";
      return $http.get(url, {
        params: {
          id: id
        }
      });
    };
    Runner.create = function(runner, cb) {
      var result, ret1;
      result = {};
      runner.longpoll = true;
      ret1 = Runner.api_create(runner);
      console.log("ret1", ret1);
      ret1.then(function(response1) {
        var ret2;
        console.log(response1);
        ret2 = Runner.api_get_details(response1.data.id);
        console.log("ret2", ret2);
        return ret2.then(function(response2) {
          console.log("response2", response2);
          cb(response2.data);
        }, function(error) {
          return console.log(error);
        });
      }, function(error) {
        return console.log(error);
      });
      return result;
    };
    return Runner;
  });

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.directive("smallProject", function(Language) {
    return {
      restrict: "EA",
      templateUrl: '/assets/projects/_small_project-c8bc8f68597233a301cdb457c68f062c.html',
      scope: {
        project: '=project'
      },
      link: function($scope, element, attrs) {
        $scope.getLanguageLabel = Language.getLabel;
        return $scope.aceOptions = {
          theme: 'twilight',
          mode: $scope.project.mode,
          onLoad: function(ace) {
            null;
            ace.renderer.setShowGutter(false);
            return null;
          }
        };
      }
    };
  });

}).call(this);
(function() {


}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.controller('TerminalCtrl', function($scope, $rootScope, Runner, Language) {
    var update_terminal;
    $rootScope.title = 'Terminal';
    update_terminal = function(Runner) {
      var term, term_itr;
      term = angular.element('.term');
      term.empty();
      term_itr = term.append('<div id="term_itr"></div>').children();
      return term_itr.terminal(function(command, term) {
        var post_data, postcmd, printcmd;
        if (command === "") {
          return;
        }
        printcmd = '';
        postcmd = '';
        if ($scope.language === "ruby") {
          printcmd = 'p ';
        } else if ($scope.language === "python") {
          printcmd = 'print ';
        } else if ($scope.language === "python3") {
          printcmd = 'print(';
          postcmd = ')';
        } else if ($scope.language === "perl") {
          printcmd = 'print ';
        }
        post_data = {
          'source_code': printcmd + command + postcmd,
          'language': $scope.language
        };
        Runner.create(post_data, function(result) {
          var errmsg, output;
          output = '';
          errmsg = '';
          if (result.build_stderr) {
            errmsg += result.build_stderr;
          }
          if (result.build_stdout) {
            errmsg += result.build_stdout;
          }
          if (result.stderr) {
            errmsg += result.stderr;
          }
          if (result.stdout) {
            output += result.stdout;
          }
          output = result.stderr + result.stdout;
          if (errmsg !== '') {
            term.error(errmsg);
          }
          term.echo(output);
        });
      }, {
        greetings: 'Paiza terminal',
        name: 'terminal_name',
        height: 200,
        prompt: $scope.language + '> '
      });
    };
    $scope.languages = Language.getLanguages();
    $scope.language = 'ruby';
    return $scope.$watch('language', function(post, pre) {
      return update_terminal(Runner);
    });
  });

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.directive("userImage", function() {
    return {
      restrict: "EA",
      templateUrl: '/assets/users/_image-a907f00ec9c7423e27d4f63c2a53d50b.html',
      scope: {
        user: '=user',
        size: '@?size'
      },
      link: function($scope, element, attrs) {
        return true;
      }
    };
  });

}).call(this);
(function() {
  var usersModule;

  usersModule = angular.module("users", ["ngResource"]);

  usersModule.factory("User", function($resource, $http) {
    var User;
    User = $resource("/api/users/:id.json", {
      id: "@id"
    });
    return User;
  });

}).call(this);
(function() {
  var app;

  app = angular.module("CodeApp");

  app.controller('UsersShowCtrl', function($scope, $location, $routeParams, User, Project, Language) {
    var id, only_favorite;
    only_favorite = false;
    if ($location.path().match(/^\/users\/show\/(.*)\/favorites/)) {
      only_favorite = true;
    }
    $scope.ctrl = $scope;
    $scope.user_id = id = $routeParams.id;
    User.get({
      id: id
    }, function(result) {
      return $scope.user = result;
    }, function(error) {
      return show_error(error);
    });
    return $scope.runQuery = function(init, offset, limit) {
      var params;
      if ($scope.paging.busy) {
        return;
      }
      if (!init && $scope.paging.count === $scope.projects.length) {
        return;
      }
      $scope.paging.busy = true;
      offset = offset || 0;
      limit = limit || 10;
      params = {
        offset: offset,
        limit: limit,
        language: $scope.language,
        only_favorite: only_favorite,
        search_text: $scope.search_text,
        user_id: id
      };
      return Project.query(params, function(result) {
        var i, len, main_source_code, project, projects;
        projects = result.projects;
        for (i = 0, len = projects.length; i < len; i++) {
          project = projects[i];
          project.mode = Language.getACEmode(project.language);
          if (project.source_files.length > 0) {
            main_source_code = project.source_files[0].body;
          } else {
            main_source_code = "";
          }
          project.linenum = count_linenum(main_source_code);
        }
        if (offset) {
          $scope.projects = $scope.projects.concat(projects);
        } else {
          $scope.projects = projects;
        }
        $scope.paging.count = result.count;
        return $scope.paging.busy = false;
      }, function(error) {
        return window.show_error(error);
      });
    };
  });

}).call(this);
(function() {
  window.show_error = function(error, callback) {
    var err_msg, ref;
    err_msg = error;
    if (error != null ? (ref = error.data) != null ? ref.error : void 0 : void 0) {
      err_msg = error.data.error;
    }
    console.log(error);
    console.log(err_msg);
    return swal({
      title: err_msg,
      text: "",
      type: "error"
    }, callback);
  };

  window.count_linenum = function(s) {
    var count, i;
    count = 1;
    i = 0;
    while ((i = s.indexOf("\n", i)) >= 0) {
      i++;
      count++;
    }
    return count;
  };

  window.isMobileSafari = function() {
    return navigator.userAgent.match(/(iPod|iPhone|iPad)/) && navigator.userAgent.match(/AppleWebKit/);
  };

}).call(this);
// This is a manifest file that'll be compiled into application.js, which will include all the files
// listed below.
//
// Any JavaScript/Coffee file within this directory, lib/assets/javascripts, vendor/assets/javascripts,
// or vendor/assets/javascripts of plugins, if any, can be referenced here using a relative path.
//
// It's not advisable to add code directly here, but if you do, it'll appear at the bottom of the
// compiled file.
//
// Read Sprockets README (https://github.com/sstephenson/sprockets#sprockets-directives) for details
// about supported directives.
//
//xxx = xxx require jquery


// commented out = require turbolinks
// commented out = require_tree .


//   https://github.com/derekprior/momentjs-rails
//xxx = xxx require moment

;
