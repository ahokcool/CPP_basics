/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astein <astein@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:51:42 by astein            #+#    #+#             */
/*   Updated: 2024/03/01 18:34:52 by astein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "freak_bible.hpp"
# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook(void);
		
		int 		get_contact_count(void) const;
		void 		run(void);
		
	private:
		Contact 	_contacts[8];
		int		 	_cur_contact;
		void 		_add(void);
		void 		_search(void) const;
		int			_get_contact_count(void) const;
};

#endif