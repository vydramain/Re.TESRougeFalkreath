(this.webpackJsonp=this.webpackJsonp||[]).push([[195],{121:function(e,t){Mousetrap=function(e){var t=e,n=t.stopCallback,r=!0;return t.stopCallback=function(e,t,a){return!r||n(e,t,a)},t.pause=function(){r=!1},t.unpause=function(){r=!0},t}(Mousetrap)},2216:function(e,t,n){n(40),n(43),e.exports=n(2250)},2250:function(e,t,n){"use strict";n.r(t);var r=n(0),a=n.n(r),i=n(11),o=n(76),s=n(79),c=n(3),u=n.n(c),l=n(26),d=n(4);function f(e){return(f="function"==typeof Symbol&&"symbol"==typeof Symbol.iterator?function(e){return typeof e}:function(e){return e&&"function"==typeof Symbol&&e.constructor===Symbol&&e!==Symbol.prototype?"symbol":typeof e})(e)}function p(e,t){for(var n=0;n<t.length;n++){var r=t[n];r.enumerable=r.enumerable||!1,r.configurable=!0,"value"in r&&(r.writable=!0),Object.defineProperty(e,r.key,r)}}function h(e,t){return!t||"object"!==f(t)&&"function"!=typeof t?function(e){if(void 0===e)throw new ReferenceError("this hasn't been initialised - super() hasn't been called");return e}(e):t}function m(e){return(m=Object.setPrototypeOf?Object.getPrototypeOf:function(e){return e.__proto__||Object.getPrototypeOf(e)})(e)}function v(e,t){return(v=Object.setPrototypeOf||function(e,t){return e.__proto__=t,e})(e,t)}var g=function(e){function t(){var e;return function(e,t){if(!(e instanceof t))throw new TypeError("Cannot call a class as a function")}(this,t),e=h(this,m(t).call(this)),u.a.bind("e",t.editWiki),e}var n,r,a;return function(e,t){if("function"!=typeof t&&null!==t)throw new TypeError("Super expression must either be null or a function");e.prototype=Object.create(t&&t.prototype,{constructor:{value:e,writable:!0,configurable:!0}}),t&&v(e,t)}(t,l["a"]),n=t,a=[{key:"editWiki",value:function(){Object(d.a)(".js-wiki-edit")}}],(r=null)&&p(n.prototype,r),a&&p(n,a),t}(),b=n(117),y=n(12),w=n(17);function j(e,t){for(var n=0;n<t.length;n++){var r=t[n];r.enumerable=r.enumerable||!1,r.configurable=!0,"value"in r&&(r.writable=!0),Object.defineProperty(e,r.key,r)}}var k=function(){function e(){var t=this;!function(e,t){if(!(e instanceof t))throw new TypeError("Cannot call a class as a function")}(this,e),this.sidebarEl=document.querySelector(".js-wiki-sidebar"),this.sidebarExpanded=!1;for(var n=document.querySelectorAll(".js-sidebar-wiki-toggle"),r=0;r<n.length;r+=1)n[r].addEventListener("click",function(e){return t.handleToggleSidebar(e)});this.newWikiForm=document.querySelector("form.new-wiki-page"),this.newWikiForm&&this.newWikiForm.addEventListener("submit",function(e){return t.handleNewWikiSubmit(e)}),window.addEventListener("resize",function(){return t.renderSidebar()}),this.renderSidebar()}var t,n,r;return t=e,r=[{key:"sidebarCanCollapse",value:function(){return"xs"===b.a.getBreakpointSize()}}],(n=[{key:"handleNewWikiSubmit",value:function(e){if(this.newWikiForm){var t=this.newWikiForm.querySelector("#new_wiki_path"),n=t.value;if(n.length>0){var r=t.getAttribute("data-wikis-path"),a=Object(y.F)(window.location.search.substr(1)),i=Object(w.d)(a,"".concat(r,"/").concat(n));Object(w.e)(i),e.preventDefault()}}}},{key:"handleToggleSidebar",value:function(e){e.preventDefault(),this.sidebarExpanded=!this.sidebarExpanded,this.renderSidebar()}},{key:"renderSidebar",value:function(){if(this.sidebarEl){var t=this.sidebarEl.classList;this.sidebarExpanded||!e.sidebarCanCollapse()?t.contains("right-sidebar-expanded")||(t.remove("right-sidebar-collapsed"),t.add("right-sidebar-expanded")):t.contains("right-sidebar-expanded")&&(t.add("right-sidebar-collapsed"),t.remove("right-sidebar-expanded"))}}}])&&j(t.prototype,n),r&&j(t,r),e}(),_=n(89),x=n(80),S=n(5),C=n.n(S),O=n(1),E=n(8),T={components:{GlModal:E.k},directives:{"gl-modal":E.l},props:{deleteWikiUrl:{type:String,required:!0,default:""},pageTitle:{type:String,required:!0,default:""},csrfToken:{type:String,required:!0,default:""}},computed:{modalId:function(){return"delete-wiki-modal"},message:function(){return Object(O.e)("WikiPageConfirmDelete|Are you sure you want to delete this page?")},title:function(){return Object(O.f)(Object(O.e)("WikiPageConfirmDelete|Delete page %{pageTitle}?"),{pageTitle:C.a.escape(this.pageTitle)},!1)}},methods:{onSubmit:function(){this.$refs.form.submit()}}},D=n(2),z=Object(D.a)(T,function(){var e=this,t=e.$createElement,n=e._self._c||t;return n("div",{staticClass:"d-inline-block"},[n("button",{directives:[{name:"gl-modal",rawName:"v-gl-modal",value:e.modalId,expression:"modalId"}],staticClass:"btn btn-danger",attrs:{type:"button"}},[e._v(e._s(e.__("Delete")))]),e._v(" "),n("gl-modal",{attrs:{title:e.title,"ok-title":e.s__("WikiPageConfirmDelete|Delete page"),"modal-id":e.modalId,"title-tag":"h4","ok-variant":"danger"},on:{ok:e.onSubmit}},[e._v("\n    "+e._s(e.message)+"\n    "),n("form",{ref:"form",staticClass:"js-requires-input",attrs:{action:e.deleteWikiUrl,method:"post"}},[n("input",{ref:"method",attrs:{type:"hidden",name:"_method",value:"delete"}}),e._v(" "),n("input",{attrs:{type:"hidden",name:"authenticity_token"},domProps:{value:e.csrfToken}})])])],1)},[],!1,null,null,null).exports;document.addEventListener("DOMContentLoaded",function(){new k,new g,new _.a,new x.a(a()(".wiki-form"));var e=document.getElementById("delete-wiki-modal-wrapper");if(e){i.default.use(o.a);var t=e.dataset,n=t.deleteWikiUrl,r=t.pageTitle;new i.default({el:e,data:{deleteWikiUrl:""},render:function(e){return e(z,{props:{pageTitle:r,deleteWikiUrl:n,csrfToken:s.a.token}})}})}})},26:function(e,t,n){"use strict";n.d(t,"a",function(){return d});var r=n(3),a=n.n(r),i=n(4),o=n(42);function s(e){return(s="function"==typeof Symbol&&"symbol"==typeof Symbol.iterator?function(e){return typeof e}:function(e){return e&&"function"==typeof Symbol&&e.constructor===Symbol&&e!==Symbol.prototype?"symbol":typeof e})(e)}function c(e,t){return!t||"object"!==s(t)&&"function"!=typeof t?function(e){if(void 0===e)throw new ReferenceError("this hasn't been initialised - super() hasn't been called");return e}(e):t}function u(e){return(u=Object.setPrototypeOf?Object.getPrototypeOf:function(e){return e.__proto__||Object.getPrototypeOf(e)})(e)}function l(e,t){return(l=Object.setPrototypeOf||function(e,t){return e.__proto__=t,e})(e,t)}var d=function(e){function t(){var e;return function(e,t){if(!(e instanceof t))throw new TypeError("Cannot call a class as a function")}(this,t),e=c(this,u(t).call(this)),a.a.bind("g p",function(){return Object(i.a)(".shortcuts-project")}),a.a.bind("g v",function(){return Object(i.a)(".shortcuts-project-activity")}),a.a.bind("g r",function(){return Object(i.a)(".shortcuts-project-releases")}),a.a.bind("g f",function(){return Object(i.a)(".shortcuts-tree")}),a.a.bind("g c",function(){return Object(i.a)(".shortcuts-commits")}),a.a.bind("g j",function(){return Object(i.a)(".shortcuts-builds")}),a.a.bind("g n",function(){return Object(i.a)(".shortcuts-network")}),a.a.bind("g d",function(){return Object(i.a)(".shortcuts-repository-charts")}),a.a.bind("g i",function(){return Object(i.a)(".shortcuts-issues")}),a.a.bind("g b",function(){return Object(i.a)(".shortcuts-issue-boards")}),a.a.bind("g m",function(){return Object(i.a)(".shortcuts-merge_requests")}),a.a.bind("g w",function(){return Object(i.a)(".shortcuts-wiki")}),a.a.bind("g s",function(){return Object(i.a)(".shortcuts-snippets")}),a.a.bind("g k",function(){return Object(i.a)(".shortcuts-kubernetes")}),a.a.bind("g e",function(){return Object(i.a)(".shortcuts-environments")}),a.a.bind("g l",function(){return Object(i.a)(".shortcuts-metrics")}),a.a.bind("i",function(){return Object(i.a)(".shortcuts-new-issue")}),e.enabledHelp.push(".hidden-shortcut.project"),e}return function(e,t){if("function"!=typeof t&&null!==t)throw new TypeError("Super expression must either be null or a function");e.prototype=Object.create(t&&t.prototype,{constructor:{value:e,writable:!0,configurable:!0}}),t&&l(e,t)}(t,o["a"]),t}()},29:function(e,t,n){"use strict";var r=n(0),a=n.n(r),i=n(14),o=n(31);function s(e,t){for(var n=0;n<t.length;n++){var r=t[n];r.enumerable=r.enumerable||!1,r.configurable=!0,"value"in r&&(r.writable=!0),Object.defineProperty(e,r.key,r)}}var c=function(){function e(t){!function(e,t){if(!(e instanceof t))throw new TypeError("Cannot call a class as a function")}(this,e),this.projectSelectInput=a()(t),this.newItemBtn=a()(".new-project-item-link"),this.resourceType=this.newItemBtn.data("type"),this.resourceLabel=this.newItemBtn.data("label"),this.formattedText=this.deriveTextVariants(),this.groupId=this.projectSelectInput.data("groupId"),this.bindEvents(),this.initLocalStorage()}var t,r,i;return t=e,(r=[{key:"bindEvents",value:function(){var e=this;this.projectSelectInput.siblings(".new-project-item-select-button").on("click",function(t){return e.openDropdown(t)}),this.newItemBtn.on("click",function(t){e.getProjectFromLocalStorage()||(t.preventDefault(),e.openDropdown(t))}),this.projectSelectInput.on("change",function(){return e.selectProject()})}},{key:"initLocalStorage",value:function(){o.a.isLocalStorageAccessSafe()&&(this.localStorageKey=["group",this.groupId,this.formattedText.localStorageItemType,"recent-project"].join("-"),this.setBtnTextFromLocalStorage())}},{key:"openDropdown",value:function(e){n.e(215).then(n.t.bind(null,230,7)).then(function(){a()(e.currentTarget).siblings(".project-item-select").select2("open")}).catch(function(){})}},{key:"selectProject",value:function(){var e=JSON.parse(this.projectSelectInput.val()),t={url:"".concat(e.url,"/").concat(this.projectSelectInput.data("relativePath")),name:e.name};this.setNewItemBtnAttributes(t),this.setProjectInLocalStorage(t)}},{key:"setBtnTextFromLocalStorage",value:function(){var e=this.getProjectFromLocalStorage();this.setNewItemBtnAttributes(e)}},{key:"setNewItemBtnAttributes",value:function(e){e?(this.newItemBtn.attr("href",e.url),this.newItemBtn.text("".concat(this.formattedText.defaultTextPrefix," in ").concat(e.name))):this.newItemBtn.text("Select project to create ".concat(this.formattedText.presetTextSuffix))}},{key:"getProjectFromLocalStorage",value:function(){var e=localStorage.getItem(this.localStorageKey);return JSON.parse(e)}},{key:"setProjectInLocalStorage",value:function(e){var t=JSON.stringify(e);localStorage.setItem(this.localStorageKey,t)}},{key:"deriveTextVariants",value:function(){var e=this.resourceLabel;return{localStorageItemType:"new-".concat(this.resourceType.split("_").join("-").slice(0,-1)),defaultTextPrefix:e,presetTextSuffix:this.resourceType.split("_").join(" ").slice(0,-1)}}}])&&s(t.prototype,r),i&&s(t,i),e}(),u=n(1);function l(){n.e(215).then(n.t.bind(null,230,7)).then(function(){a()(".ajax-project-select").each(function(e,t){var n,r,o=a()(t).data("simpleFilter")||!1;return this.groupId=a()(t).data("groupId"),this.includeGroups=a()(t).data("includeGroups"),this.allProjects=a()(t).data("allProjects")||!1,this.orderBy=a()(t).data("orderBy")||"id",this.withIssuesEnabled=a()(t).data("withIssuesEnabled"),this.withMergeRequestsEnabled=a()(t).data("withMergeRequestsEnabled"),this.withShared=void 0===a()(t).data("withShared")||a()(t).data("withShared"),this.includeProjectsInSubgroups=a()(t).data("includeProjectsInSubgroups")||!1,this.allowClear=a()(t).data("allowClear")||!1,n=Object(u.e)("ProjectSelect|Search for project"),this.includeGroups&&(n+=Object(u.e)("ProjectSelect| or group")),a()(t).select2({placeholder:n,minimumInputLength:0,query:(r=this,function(e){var t,n;return t=function(t){var n;return n={results:t},e.callback(n)},n=r.includeGroups?function(n){var r;return r=function(e){var r;return r=e.concat(n),t(r)},i.a.groups(e.term,{},r)}:t,r.groupId?i.a.groupProjects(r.groupId,e.term,{with_issues_enabled:r.withIssuesEnabled,with_merge_requests_enabled:r.withMergeRequestsEnabled,with_shared:r.withShared,include_subgroups:r.includeProjectsInSubgroups},n):i.a.projects(e.term,{order_by:r.orderBy,with_issues_enabled:r.withIssuesEnabled,with_merge_requests_enabled:r.withMergeRequestsEnabled,membership:!r.allProjects},n)}),id:function(e){return o?e.id:JSON.stringify({name:e.name,url:e.web_url})},text:function(e){return e.name_with_namespace||e.name},initSelection:function(e,t){return i.a.project(e.val()).then(function(e){var n=e.data;return t(n)})},allowClear:this.allowClear,dropdownCssClass:"ajax-project-dropdown"}),o?t:new c(t)})}).catch(function(){})}n.d(t,"a",function(){return l})},30:function(e,t,n){"use strict";n.d(t,"a",function(){return p});var r=n(0),a=n.n(r),i=n(13),o=n.n(i),s=n(1),c=n(17),u=n(6),l=n(7),d=n(29);function f(e,t){for(var n=0;n<t.length;n++){var r=t[n];r.enumerable=r.enumerable||!1,r.configurable=!0,"value"in r&&(r.writable=!0),Object.defineProperty(e,r.key,r)}}var p=function(){function e(){!function(e,t){if(!(e instanceof t))throw new TypeError("Cannot call a class as a function")}(this,e);var t=a()("ul.clone-options-dropdown"),n=a()("#project_clone"),r=a()(".js-git-clone-holder .js-clone-dropdown-label"),i=document.querySelector(".js-mobile-git-clone .js-clone-dropdown-label"),s=r.text().trim();s.length>0&&a()("a:contains('".concat(s,"')"),t).addClass("is-active"),a()("a",t).on("click",function(e){e.preventDefault();var r=a()(e.currentTarget),o=r.attr("href"),s=r.data("cloneType");a()(".is-active",t).removeClass("is-active"),a()('a[data-clone-type="'.concat(s,'"]')).each(function(){var e=a()(this),t=e.find(".dropdown-menu-inner-title").text(),n=e.closest(".project-clone-holder").find(".js-clone-dropdown-label");e.toggleClass("is-active"),n.text(t)}),a()("#modal-geo-info").data({cloneUrlSecondary:r.attr("href"),cloneUrlPrimary:r.data("primaryUrl")||""}),i?i.dataset.clipboardText=o:n.val(o),a()(".js-git-empty .js-clone").text(o)}),e.initRefSwitcher(),a()(".project-refs-select").on("change",function(){return a()(this).parents("form").submit()}),a()(".hide-no-ssh-message").on("click",function(e){return o.a.set("hide_no_ssh_message","false"),a()(this).parents(".no-ssh-key-message").remove(),e.preventDefault()}),a()(".hide-no-password-message").on("click",function(e){return o.a.set("hide_no_password_message","false"),a()(this).parents(".no-password-message").remove(),e.preventDefault()}),a()(".hide-shared-runner-limit-message").on("click",function(e){var t=a()(this).parents(".shared-runner-quota-message"),n=t.data("scope");o.a.set("hide_shared_runner_quota_message","false",{path:n}),t.remove(),e.preventDefault()}),a()(".hide-auto-devops-implicitly-enabled-banner").on("click",function(e){var t=a()(this).data("project-id"),n="hide_auto_devops_implicitly_enabled_banner_".concat(t);return o.a.set(n,"false"),a()(this).parents(".auto-devops-implicitly-enabled-banner").remove(),e.preventDefault()}),e.projectSelectDropdown()}var t,n,r;return t=e,r=[{key:"projectSelectDropdown",value:function(){Object(d.a)(),a()(".project-item-select").on("click",function(t){return e.changeProject(a()(t.currentTarget).val())})}},{key:"changeProject",value:function(e){return window.location=e}},{key:"initRefSwitcher",value:function(){var e=document.createElement("li"),t=document.createElement("a");return t.href="#",a()(".js-project-refs-dropdown").each(function(){var n,r;return n=a()(this),r=n.data("selected"),n.glDropdown({data:function(e,t){u.a.get(n.data("refsUrl"),{params:{ref:n.data("ref"),search:e}}).then(function(e){var n=e.data;return t(n)}).catch(function(){return Object(l.a)(Object(s.a)("An error occurred while getting projects"))})},selectable:!0,filterable:!0,filterRemote:!0,filterByText:!0,inputFieldName:n.data("inputFieldName"),fieldName:n.data("fieldName"),renderRow:function(n){var a=e.cloneNode(!1);if(null!=n.header)a.className="dropdown-header",a.textContent=n.header;else{var i=t.cloneNode(!1);n===r&&(i.className="is-active"),i.textContent=n,i.dataset.ref=n,a.appendChild(i)}return a},id:function(e,t){return t.attr("data-ref")},toggleLabel:function(e,t){return t.text().trim()},clicked:function(e){if(e.e.preventDefault(),a()('input[name="ref"]').length){var t=n.closest("form"),r=n.data("visit"),i=!!r||r,o=t.attr("action"),s=-1===o.indexOf("?")?"?":"&";i&&Object(c.i)("".concat(o).concat(s).concat(t.serialize()))}}})})}}],(n=null)&&f(t.prototype,n),r&&f(t,r),e}()},43:function(e,t,n){"use strict";n.r(t);var r=n(35),a=n(34),i=n(30),o=n(26);document.addEventListener("DOMContentLoaded",function(){var e=document.body.dataset.page;if(["projects:clusters:new","projects:clusters:create_gcp","projects:clusters:create_user"].indexOf(e)>-1){var t=document.querySelector(".gcp-signup-offer");a.a.factory(t),Object(r.a)()}new i.a,new o.a})},80:function(e,t,n){"use strict";var r=n(0),a=n.n(r),i=n(57),o=n.n(i),s=n(65),c=n(33),u=n.n(c),l=n(5),d=n.n(l),f=(n(190),n(79)),p=n(6),h=n(1);function m(e){var t,n,r,i,o,s,c,l=e.find(".button-attach-file"),m=e.find(".attaching-file-message"),v=e.find(".button-cancel-uploading-files"),g=e.find(".retry-uploading-link"),b=e.find(".uploading-progress"),y=e.find(".uploading-error-container"),w=e.find(".uploading-error-message"),j=e.find(".uploading-progress-container"),k=e.data("uploads-path")||window.uploads_path||null,_=gon.max_file_size||10,x=e.find(".js-gfm-input");x.wrap('<div class="div-dropzone"></div>'),x.on("paste",function(e){return t(e)});var S=x.closest(".md-area");e.setupMarkdownPreview();var C=e.find(".div-dropzone");if(C.parent().addClass("div-dropzone-wrapper"),C.append('<div class="div-dropzone-hover"></div>'),C.find(".div-dropzone-hover").append('<i class="fa fa-paperclip div-dropzone-icon"></i>'),!k)return C.addClass("js-invalid-dropzone"),null;var O=C.dropzone({url:k,dictDefaultMessage:"",clickable:!0,paramName:"file",maxFilesize:_,uploadMultiple:!1,headers:f.a.headers,previewContainer:!1,processing:function(){return a()(".div-dropzone-alert").alert("close")},dragover:function(){S.addClass("is-dropzone-hover"),e.find(".div-dropzone-hover").css("opacity",.7)},dragleave:function(){S.removeClass("is-dropzone-hover"),e.find(".div-dropzone-hover").css("opacity",0)},drop:function(){S.removeClass("is-dropzone-hover"),e.find(".div-dropzone-hover").css("opacity",0),x.focus()},success:function(e,t){var a=this.getQueuedFiles().length+this.getUploadingFiles().length,i=a>=1;n(t.link.markdown,i),a||l.removeClass("hide"),r(t.link.url)},error:function(e){var t,n=arguments.length>1&&void 0!==arguments[1]?arguments[1]:Object(h.a)("Attaching the file failed."),r=arguments.length>2?arguments[2]:void 0,a=!(t=n||r.responseText)||d.a.isString(t)?t:t.message;y.removeClass("hide"),w.html(a),l.addClass("hide"),v.addClass("hide")},totaluploadprogress:function(e){i(this.files,m),b.text("".concat(Math.round(e),"%"))},sending:function(){l.addClass("hide"),y.addClass("hide"),j.removeClass("hide"),v.removeClass("hide")},removedfile:function(){l.removeClass("hide"),v.addClass("hide"),j.addClass("hide"),y.addClass("hide")},queuecomplete:function(){a()(".dz-preview").remove(),a()(".markdown-area").trigger("input"),j.addClass("hide"),v.addClass("hide")}}),E=a()(O[0]).children("textarea");v.on("click",function(e){e.preventDefault(),e.stopPropagation(),u.a.forElement(C.get(0)).removeAllFiles(!0)}),g.on("click",function(e){var t=u.a.forElement(e.target.closest(".js-main-target-form").querySelector(".div-dropzone")),n=t.files;e.preventDefault(),t.removeAllFiles(!0),n.map(function(e){var n=e;return n.status===u.a.ERROR&&(n.status=void 0,n.accepted=void 0),t.addFile(n)})}),t=function(e){var t=e.originalEvent;if(t.clipboardData&&t.clipboardData.items){var r=o(t);if(r){e.preventDefault();var a=s(t)||"image.png",i="{{".concat(a,"}}");return n(i),c(r.getAsFile(),a)}}},o=function(e){for(var t=0;t<e.clipboardData.items.length;){var n=e.clipboardData.items[t];if(-1!==n.type.indexOf("image"))return n;t+=1}return!1},n=function(e,t){var n=e;t&&(n+="\n\n");var r=E.get(0),i=r.selectionStart,o=r.selectionEnd,s=a()(E).val().length,c=a()(E).val().substring(0,i),u=a()(E).val().substring(o,s);return a()(E).val(c+n+u),r.setSelectionRange(i+n.length,o+n.length),r.style.height="".concat(r.scrollHeight,"px"),x.get(0).dispatchEvent(new Event("input")),x.trigger("input")},r=function(t){a()(e).append('<input type="hidden" name="files[]" value="'.concat(d.a.escape(t),'">'))},s=function(e){var t;return window.clipboardData&&window.clipboardData.getData?t=window.clipboardData.getData("Text"):e.clipboardData&&e.clipboardData.getData&&(t=e.clipboardData.getData("text/plain")),(t=t.split("\r"))[0]};var T=function(){return j.addClass("hide")};return c=function(t,n){var r=new FormData;r.append("file",t,n),j.removeClass("hide"),e.find(".div-dropzone-alert").alert("close"),p.a.post(k,r).then(function(e){var t=e.data.link.markdown;!function(e,t){var n=a()(E);n.val(function(n,r){return r.replace("{{".concat(e,"}}"),t)}),n.trigger("change")}(n,t),T()}).catch(function(e){var t;t=e.response.data.message,y.removeClass("hide"),w.html(t),T()})},i=function(e,t){var n=e.filter(function(e){return"uploading"===e.status||"queued"===e.status}).length,r=Object(h.d)("Attaching a file","Attaching %d files",n);t.text("".concat(r," -"))},e.find(".markdown-selector").click(function(e){e.preventDefault(),a()(this).closest(".gfm-form").find(".div-dropzone").click(),x.focus()}),u.a.forElement(C.get(0))}u.a.autoDiscover=!1;var v=n(77);function g(e,t){for(var n=0;n<t.length;n++){var r=t[n];r.enumerable=r.enumerable||!1,r.configurable=!0,"value"in r&&(r.writable=!0),Object.defineProperty(e,r.key,r)}}n.d(t,"a",function(){return b});var b=function(){function e(t){var n=this,r=arguments.length>1&&void 0!==arguments[1]?arguments[1]:{};!function(e,t){if(!(e instanceof t))throw new TypeError("Cannot call a class as a function")}(this,e),this.form=t,this.textarea=this.form.find("textarea.js-gfm-input"),this.enableGFM=Object.assign({},s.b,r);var a=gl.GfmAutoComplete&&gl.GfmAutoComplete.dataSources||{};Object.keys(this.enableGFM).forEach(function(e){"emojis"!==e&&(n.enableGFM[e]=Boolean(a[e]))}),this.destroy(),this.setupForm(),this.form.data("glForm",this)}var t,n,r;return t=e,(n=[{key:"destroy",value:function(){this.clearEventListeners(),this.autoComplete&&this.autoComplete.destroy(),this.form.data("glForm",null)}},{key:"setupForm",value:function(){var e=this.form.is(":not(.gfm-form)");this.form.removeClass("js-new-note-form"),e&&(this.form.find(".div-dropzone").remove(),this.form.addClass("gfm-form"),gl.utils.disableButtonIfEmptyField(this.form.find(".js-note-text"),this.form.find(".js-comment-button, .js-note-new-discussion")),this.autoComplete=new s.a(gl.GfmAutoComplete&&gl.GfmAutoComplete.dataSources),this.autoComplete.setup(this.form.find(".js-gfm-input"),this.enableGFM),m(this.form),o()(this.textarea)),this.addEventListeners(),Object(v.b)(this.form),this.form.show(),this.isAutosizeable&&this.setupAutosize()}},{key:"setupAutosize",value:function(){var e=this;this.textarea.off("autosize:resized").on("autosize:resized",this.setHeightData.bind(this)),this.textarea.off("mouseup.autosize").on("mouseup.autosize",this.destroyAutosize.bind(this)),setTimeout(function(){o()(e.textarea),e.textarea.css("resize","vertical")},0)}},{key:"setHeightData",value:function(){this.textarea.data("height",this.textarea.outerHeight())}},{key:"destroyAutosize",value:function(){var e=this.textarea.outerHeight();this.textarea.data("height")!==e&&(o.a.destroy(this.textarea),this.textarea.data("height",e),this.textarea.outerHeight(e),this.textarea.css("max-height",window.outerHeight))}},{key:"clearEventListeners",value:function(){this.textarea.off("focus"),this.textarea.off("blur"),Object(v.c)(this.form)}},{key:"addEventListeners",value:function(){this.textarea.on("focus",function(){a()(this).closest(".md-area").addClass("is-focused")}),this.textarea.on("blur",function(){a()(this).closest(".md-area").removeClass("is-focused")})}}])&&g(t.prototype,n),r&&g(t,r),e}()},89:function(e,t,n){"use strict";n.d(t,"a",function(){return l});var r=n(0),a=n.n(r),i=(n(189),n(33)),o=n.n(i),s=n(3),c=n.n(s);n(121);function u(e,t){for(var n=0;n<t.length;n++){var r=t[n];r.enumerable=r.enumerable||!1,r.configurable=!0,"value"in r&&(r.writable=!0),Object.defineProperty(e,r.key,r)}}o.a.autoDiscover=!1;var l=function(){function e(){var t;!function(e,t){if(!(e instanceof t))throw new TypeError("Cannot call a class as a function")}(this,e),this.active_backdrop=null,this.active_textarea=null,a()(document).on("click",".js-zen-enter",function(e){return e.preventDefault(),a()(e.currentTarget).trigger("zen_mode:enter")}),a()(document).on("click",".js-zen-leave",function(e){return e.preventDefault(),a()(e.currentTarget).trigger("zen_mode:leave")}),a()(document).on("zen_mode:enter",(t=this,function(e){return t.enter(a()(e.target).closest(".md-area").find(".zen-backdrop"))})),a()(document).on("zen_mode:leave",function(e){return function(t){return e.exit()}}(this)),a()(document).on("keydown",function(e){if(27===e.keyCode)return e.preventDefault(),a()(document).trigger("zen_mode:leave")})}var t,n,r;return t=e,(n=[{key:"enter",value:function(e){c.a.pause(),this.active_backdrop=a()(e),this.active_backdrop.addClass("fullscreen"),this.active_textarea=this.active_backdrop.find("textarea"),this.active_textarea.removeAttr("style"),this.active_textarea.focus()}},{key:"exit",value:function(){if(this.active_textarea){c.a.unpause(),this.active_textarea.closest(".zen-backdrop").removeClass("fullscreen"),this.scrollTo(this.active_textarea),this.active_textarea=null,this.active_backdrop=null;var e=a()(".div-dropzone");e&&!e.hasClass("js-invalid-dropzone")&&o.a.forElement(".div-dropzone").enable()}}},{key:"scrollTo",value:function(e){return a.a.scrollTo(e,0,{offset:-150})}}])&&u(t.prototype,n),r&&u(t,r),e}()}},[[2216,1,0,2,3]]]);
//# sourceMappingURL=pages.projects.wikis.71f06d5c.chunk.js.map