/**
 * The Seeks proxy and plugin framework are part of the SEEKS project.
 * Copyright (C) 2009 Emmanuel Benazera, juban@free.fr
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STATIC_RENDERER_H
#define STATIC_RENDERER_H

#include "websearch.h"
#include "clustering.h"

namespace seeks_plugins
{
   class static_renderer
     {
      public:
	/*- cgi. -*/
	static void register_cgi(websearch *wbs);
	
	/*- rendering functions. -*/
	static void render_query(const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters,
				 hash_map<const char*,const char*,hash<const char*>,eqstr> *exports,
				 std::string &html_encoded_query);
	
	static void render_clean_query(const std::string &html_encoded_query,
				       hash_map<const char*,const char*,hash<const char*>,eqstr> *exports,
				       std::string &query_clean);
	
	static void render_suggestions(const query_context *qc,
				       hash_map<const char*,const char*,hash<const char*>,eqstr> *exports);
	
	static void render_snippets(const std::string &query_clean,
				    const int &current_page,
				    const std::vector<search_snippet*> &snippets,
				    hash_map<const char*,const char*,hash<const char*>,eqstr> *exports);
	
	static void render_clustered_snippets(const std::string &query_clean,
					      const std::string &html_encoded_query,
					      const int &current_page,
					      cluster *clusters,
					      const short &K,
					      const query_context *qc,
					      const hash_map<const char*,const char*,hash<const char*>,eqstr> *parameters,
					      hash_map<const char*,const char*,hash<const char*>,eqstr> *exports);
	
	static std::string render_cluster_label(const cluster &cl);
	
	static std::string render_cluster_label_query_link(const std::string &html_encoded_query,
							   const cluster &cl,
							   const hash_map<const char*,const char*,hash<const char*>,eqstr> *exports);
	
	static void render_current_page(const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters,
					hash_map<const char*,const char*,hash<const char*>,eqstr> *exports,
					int &current_page);
	
	static void render_expansion(const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters,
				     hash_map<const char*,const char*,hash<const char*>,eqstr> *exports,
				     std::string &expansion);
	
	static void render_next_page_link(const int &current_page,
					  const size_t &snippets_size,
					  const std::string &html_encoded_query,
					  const std::string &expansion,
					  hash_map<const char*,const char*,hash<const char*>,eqstr> *exports);
	
	static void render_prev_page_link(const int &current_page,
					  const size_t &snippets_size,
					  const std::string &html_encoded_query,
					  const std::string &expansion,
					  hash_map<const char*,const char*,hash<const char*>,eqstr> *exports);

	static void render_nclusters(const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters,
				     hash_map<const char*,const char*,hash<const char*>,eqstr> *exports);
	  
	static hash_map<const char*,const char*,hash<const char*>,eqstr>* websearch_exports(client_state *csp);
	
	/*- renderer. -*/
	static sp_err render_hp(client_state *csp, http_response *rsp);
	
	static sp_err render_result_page_static(const std::vector<search_snippet*> &snippets,
						client_state *csp, http_response *rsp,
						const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters,
						const query_context *qc);

	static sp_err render_clustered_result_page_static(cluster *clusters,
							  const short &K,
							  client_state *csp, http_response *rsp,
							  const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters,
							  const query_context *qc);
	
	static sp_err render_neighbors_result_page(client_state *csp, http_response *rsp,
						   const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters,
						   query_context *qc, const int &mode);
     
	/* static sp_err render_clustered_types_page(client_state *csp, http_response *rsp,
						  const hash_map<const char*, const char*, hash<const char*>, eqstr> *parameters); */
     };
   
} /* end of namespace. */

#endif
