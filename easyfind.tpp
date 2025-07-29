/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:09:35 by mpietrza          #+#    #+#             */
/*   Updated: 2025/07/29 12:20:51 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator easyfind (T&container, int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::out_of_range("Value not found");
	return it;
}
